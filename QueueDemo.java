import java.util.Scanner;
class Node
{
	Node next;
	int data;
}
class Queue extends Node
{
	Node front=null,rear=null;
	Queue()
	{
		if(front==null)
		{
			front=new Node();
			rear=front;
		}
		rear.data=10;
		rear.next=null;
		
	}
	Queue(int x)
	{
		if(front==null)
		{
			front=new Node();
			rear=front;
		}
		rear.data=x;
		rear.next=null;
	}
	void insert(int x)
	{
		Node p=new Node();
		p.data=x;
		p.next=null;
		rear.next=p;
		rear=p;
	}
	int delete()
	{
		if(front==null)
		{
			System.out.println("QUEUE UNDERFLOW");
			return -65536;
		}
		Node p;
		p=front;
		front=front.next;
		int x=p.data;
		p.next=null;
		p=null;
		return x;
	}
	void traverse()
	{
		if(front==null)
		{
			System.out.println("QUEUE UNDERFLOW");
			return;
		}
		Node p;
		p=front;
		System.out.println("THE ELEMENTS IN THE QUEUE ARE: ");
		while(p!=null)
		{
			System.out.print(p.data+" ");
			p=p.next;
		}
		System.out.println();
	}
}
class QueueDemo
{
	public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);
		int op,ans;
		Queue q1=null;
		do
		{
			System.out.println("\nENTER YOUR CHOICE \n1.INSERT\n2.DELETE\n3.TRAVERSE\n4.EXIT \nchoose wisely live well");
			op=in.nextInt();
			switch(op)
			{
				case 1:System.out.println("Enter the element :");
						int x=in.nextInt();
						if(q1==null)
							q1=new Queue(x);
						else
							q1.insert(x);
						System.out.println("Element inserted SUCCESSFULLY");
						break;
				case 2:ans=q1.delete();
						if(ans!=-65536)
							System.out.println("THE ELEMENT DELETED IS "+ans);
						break;
				case 3:q1.traverse();
						break;
				case 4:break;
				default:System.out.println("INVALID CHOICE RE ENTER IT:");
						break;
			}
		}while(op!=4);
	}
}