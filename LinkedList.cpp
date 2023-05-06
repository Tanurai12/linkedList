
//linked list pprogram by Tanuuuu(meeee)-------------------------------->>>>>>>>>>>>>>>>>
#include<iostream>
#include<cstdlib>

using namespace std;
class node
{
    public:        //after creating this class we make a seprate type node it is a data type that contains data part and pointer to a next node 
    int value;
    node *next;
    node()       //it is a constructor that run when we create dynamic memeory allocation ex--->   " node *temp= new node();"
    {
        value=0;
        next=NULL;
    }

};
class LinkedList      //it is a class on which we will perform operation
{
    node *head;    //it is a head pointer
    public:

    LinkedList()  //constructor when we'll create the object then first head will be null
    {
       head=NULL;
    }


        //insert  at  the end node
        void insertAtEnd(int v)
        {
            node *temp= new node();  //create a  node
            temp->value=v;      //assigned a value
            if(head==NULL)     //for the first node condition will be true
                head=temp;     //them the first node be
            else
            {
                node *t= head;     //create a node for traversing the list
                while(t->next!=NULL)  //jab tak next null nahi ho jata tb tk
                t=t->next;        //t ka next t me assign krna hai
                t->next=temp;    //if you got the null then  assign the temp node to the node
            }
        }

        //print the linked list
        void printLL()
         {
            node *t = head;  //create the temp node and assigned the head to the node
            while(t!=NULL)     //jb tk t null na ho jaye
            {
                 cout<<t->value<<"->";  //print the value of t which is pointed by t
                 t=t->next;             // assign next of t to t 
            }

          cout<<endl<<endl;
         }

         //insert at the begin

        void insertAtBegin(int v)
        {
             node *t=new node();  //create a node
             t->value=v;           //assign the value to the t node
             if(head==NULL)       //agar head empty ho tb head 
             head=t;     //assign t to head
         else
         {

            t->next=head;  //t ke next me head
            head=t;     // and then assign t to head

         }
        }

        //insert at middle
        void insertAtMiddle(int pos,int v) //we will take to arguments position and value
         {
             node *temp=new node();  //we will create a node 
             temp->value=v;         //then we will assign value to the temp
             if(pos==1)          //if position is 1 then the beginning code is run
             {
                temp->next=head;    //code pf insert at beggining
                head=temp;
             }
             else
            {
                node *t=head;         //we will create a node 
               
             while(pos>2)      //if position  graeter than 2 then while condition willbe run 
             {
                pos--;
                if(t!=NULL)  //for reaching the correct position
                {
                    t=t->next;
                }
                else //if user enter the wrong position then else will be run
                {
                    cout<<"wrong position "<<endl;
                    return ;
                }
             }
                 temp->next=t->next; //after while it will be run or in case of position 2  it will also run because we want to enter the value in the next of t and 
                 t->next=temp;         //with this statemet we will directly put
            }

         }

         //searching the element in list

    void search(int v)
    {
        node *temp= head;  //create a node for travers 
        if(head==NULL)   //if head is null then list will bw empty
        {
            cout<<"list is empty"<<endl;
        }
        else  //otherwise
        {
            int count=0;
             while(temp!=NULL)  //jabtak temp null nahi ho jata
              {
                    count++;
                    if(temp->value==v)  //if value found
                     {
                        cout<<"element found ("<<temp->value<<") at position "<<count<<endl;  //simply prinnt
                        return;
                     }
         
                 temp=temp->next; //or assign temp ka next to temp
    
             }
             cout<<"value not found"<<endl;//otherwise value not found
        }
    }

    //delete the middle

    void deleteAtMiddle(int pos)  //take a position to delete
    {
        node *temp = head;  //create a node and assign the head
        if(head==NULL)      //if head is null then print list is empty
          cout<<"list is empty";
       
        if(pos==1)  //if position 1 
        {
            head=head->next;
            cout<<"value deleted is "<<temp->value<<endl; //delete the beginning will be run
            free(temp);
        }
        else   //otherwise
        {
            while(pos>2)  //like insertion at the middle
            {
                pos--;
                 if(temp!=NULL)  //if temp null nahi hai 
                {
                    temp=temp->next;  //assign thiss
                }
                else
                {
                    cout<<"wrong position "<<endl; //or print the wrong position
                    return ;
                }

            }
                  node * t = temp->next;  
                  temp->next = t->next;
                  cout<<t->value<<" deleted"<<endl;
                  delete t;

        }
    }
    void deleteAtBegin()
    {
        node *temp=head;
        if(head==NULL)
        cout<<"list is empty"<<endl;
        else
        {
            head=head->next;
            cout<<"value deleted "<<temp->value<<endl;
            free(temp);
        }
    }

    void deleteAtEnd()
    {
        node *t=head, *temp;
        if(head==NULL)
        cout<<"list is empty"<<endl;
        else
        {
             while(t->next->next!=NULL)
                {
                  t=t->next;
                
                }
             temp=t->next;
            t->next=NULL;
            cout<<"deleted value"<<temp->value<<endl;
            delete temp;
            }
    }

};
int main()
{
    LinkedList l1;
    int choice, value,position;
    while(1)

    {
      
        cout<<"1. insert element at end "<<endl;
        cout<<"2. insert element at beginning"<<endl;
        cout<<"3. insert element at middle"<<endl;
        cout<<"4. delete element from the end "<<endl;
        cout<<"5. delete element from the beginning"<<endl;
        cout<<"6. delete element from the particular location"<<endl;
        cout<<"7. search"<<endl;
        cout<<"8. print the linkedlist"<<endl;
        cout<<"9. exit"<<endl;

        cout<<"enter your choice"<<endl;
        cin>>choice;

       

        switch(choice)
        {
            

            case 1:
            {
                cout<<"enter a value"<<endl;
                cin>>value;
                l1.insertAtEnd(value); 
                break;

            }

            case 2:
            {
                cout<<"enter a value"<<endl;
                cin>>value;
                l1.insertAtBegin(value); 
                break;
            }
            case 3:
            {
                cout<<"enter a  position and value "<<endl;
                cin>>position>>value;
                l1.insertAtMiddle(position,value); 
                break;

            }

            case 4:
            {
                l1.deleteAtEnd();
                break;
            }
             case 5:
            {
                l1.deleteAtBegin();
                break;
            }
             case 6:
            {
                cout<<"enter the position that u want to delete"<<endl;
                cin>>position;

                l1.deleteAtMiddle(position);
                break;
            }
             case 7:
            {
                 cout<<"enter a value"<<endl;
                 cin>>value;

                 l1.search(value);
                 break;

            }
             case 8:
            {
               
               l1.printLL();
               break;
            }

            case 9:
            exit(0);
        }
    }

    return 0;
}