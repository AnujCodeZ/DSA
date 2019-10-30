package com.company;

import java.util.Scanner;

public class segmentTree {
    private class Node{
         Node leftnode;
         Node rightnode;
         int data;
         int startinterval;
         int endinterval;


    }
    Node root;
    public void buildtree(int a[],int length){
        this.root=constructtree(a,0,length-1);
    }

    private Node constructtree(int[] a, int si, int ei) {
        if (si==ei){
            Node leafnode=new Node();
            leafnode.data=a[si];
            leafnode.startinterval=si;
            leafnode.endinterval=ei;
            return leafnode;

        }
        Node node=new Node();
        node.startinterval=si;
        node.endinterval=ei;
        int mid=(si+ei)/2;
        node.leftnode=constructtree(a,si,mid);
        node.rightnode=constructtree(a,mid+1,ei);
        node.data=node.leftnode.data+node.rightnode.data;
        return node;
    }
    public int  findsum(int si,int ei){
        int sum=findsummain(root,si,ei);
        return sum;
    }

    private int findsummain(Node node, int si, int ei) {
        if (checkinterval(node.startinterval,node.endinterval,si,ei)==1){
            return node.data;
        }
        else if (checkinterval(node.startinterval,node.endinterval,si,ei)==-1) {
//            System.out.println(sum);
            return 0;
        }

        else {
                int left=findsummain(node.leftnode,si,ei);
                int right=findsummain(node.rightnode,si,ei);
                return left+right;
            }


    }
    public void update(int index){
        root.data=updatee(root,index);
    }

    private int updatee(Node node, int index) {
        if (index>=node.startinterval&&index<=node.endinterval){
            if (index==node.startinterval&&index==node.endinterval){
                if (node.data==0){
                    node.data=1;
                }
                else node.data=0;
            }
            else {
                int left=updatee(node.leftnode,index);
                int right=updatee(node.rightnode,index);
                node.data=left+right;
            }
        }
        return node.data;
    }

    private int checkinterval(int nodestartinterval, int nodeendinterval, int si, int ei) {
        if ((nodestartinterval >= si) && nodeendinterval <= ei){
            return 1;    //1 means it is full lying inside intervals
        }

        if (si>nodeendinterval||ei<nodestartinterval){
            return -1;  //not all lying inside intervals
        }
        else {
            return 0;    //partially lying
        }
    }


    public void display(){
        displaymain(root);
    }

    private void displaymain(Node node) {
        if(node==null){
            return;
        }
        System.out.println(node.data +" interval {"+node.startinterval+","+node.endinterval+"}");
        displaymain(node.leftnode);
        displaymain(node.rightnode);
    }

    public static void main(String[] args) {
        segmentTree tree=new segmentTree();
        Scanner input=new Scanner(System.in);
        int n=input.nextInt();
        int a[]=new int[n];
        for (int i = 0; i <n ; i++) {
            a[i]=0;

        }
        tree.buildtree(a,n);
       int q=input.nextInt();
        for (int i = 0; i <q ; i++) {
            int b=input.nextInt();
            int c=input.nextInt();
            int d=input.nextInt();
            if (b==0){
                for (int j = c; j <=d ; j++) {
                    tree.update(j);

                }
            }
            else if (b==1){
                System.out.println(tree.findsum(c,d));
            }

        }


    }
}
