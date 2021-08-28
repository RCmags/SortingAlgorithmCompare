#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

//Custom Linked-list class: [not all bugs fixed]
class linked_list {

    private:
    //Variables:
        struct node {
            int data;
            node *link;
        };

        node *head, *tail;

    //----- Private functions:

                    //---- Node insertion:

        void add_last( int value ) {

            if( length == 0 ) {
                head = new node;
                head->data = value;
                head->link = NULL;
                //cout << head->data << endl;
            } else if (length == 1) {
                tail = new node;
                tail->data = value;
                tail->link = NULL;
                //
                head->link = tail;
                //cout << tail->data << endl;
            } else {
                tail->link = new node;
                tail = tail->link;
                tail->data = value;
                tail->link = NULL;
                //cout << tail->data << endl;
            }
            length += 1;
        } //End of add_last

        //
        void add_front( int value ) {
            if( length == 0 ) {
                add_last( value );
            } else if( length == 1 ) {
                tail = head;
                head = new node;
                head->data = value;
                head->link = tail;
                //cout << head->data << endl;
                length += 1;
            } else {
                node *temp;
                temp = new node;
                temp->data = value;
                temp->link = head;
                head = temp;
                //cout << head->data << endl;
                length += 1;
            }
        } //End of add_front


                        //---- Node Removal:

        void remove_last( void ) {
                if( length > 1 ) {
                    node *curr;
                    curr = head;
                    for( int index = 1; index < (length-1); index += 1 ) {
                        curr = curr->link;
                        //cout << "Pre deletion link: " << curr->data << endl;
                    }
                    delete (curr->link);
                    curr->link = NULL;
                }
                else {
                    delete head;
                    head = NULL;
                }
        } //End of remove last

        //
        void remove_first( void ) {
            if( length != 1 ) {
                node *temp;
                temp = head->link;
                //
                delete head;
                head = temp;
            } else {
                delete head;
                head = NULL;
            }
        } //End of remove first


    public:
    //Variables:
        int length;

     //----- Public functions:

        // Constructor and destructor
        linked_list() {
            head = NULL;
            tail = NULL;
            length = 0;
        }

        ~linked_list () {
            cout << "class removed" << endl;
        }

                //------ Node insertion:

        void insert_node( int value , int pos ) {
            if( pos >= 0 ) {
                if( pos == 0 ) {
                    add_front( value );
                }
                else if( (pos>=1) && (pos<length) ) {
                    //cout << "inside list" << endl;
                    node *curr;
                    curr = head;
                    for( int index = 1; index < length ; index += 1 ) {
                        if( index == pos ) {
                            node *temp;
                            temp = new node;
                            temp->data = value;
                            //
                            temp->link = (curr->link);
                            curr->link = temp;
                            //
                            break;
                            //cout << "Out of for loop" << endl;
                            }
                        curr = curr->link;
                        //cout << "scanning " << index << endl;
                    }
                    length +=1;
                }
                else {
                    //cout << "Outside list - adding empty spaces" << endl;
                    for( int index = length ; index <= pos ; index += 1 ) {
                            if( index < pos ) {
                                add_last( 0 );
                            } else {
                                add_last( value );
                            }
                    }
                }
            } else {
                cout << "Cannot accept negative index" << endl;
            }
        }   //End of insert node


                //------ Node deletion:

        void delete_link( int pos ) {
            if( pos >= 0 ) {
                if( (pos >= 0) && (pos < length) ) {
                    if( pos == 0 ) {
                        //cout << "removing first" << endl;
                        remove_first();
                    }
                    else if ( (pos > 0) && (pos < (length-1) ) ) {
                        //cout << "removing middle" << endl;
                        node *curr;
                        curr = head;
                        for( int index = 1; index < (length-1) ; index += 1 ) {
                            if( index == pos ) {
                                node *temp;
                                temp = curr->link->link;
                                //
                                delete curr->link;
                                //
                                curr->link = temp;
                                //
                                break;
                            }
                            curr = curr->link;
                        }
                    }
                    else {
                        cout << "removing last" << endl;
                        remove_last();
                    }
                    //
                    length -= 1;
                }
                else {
                    cout << "No data to delete" << endl;
                }
            } else {
                cout << "Cannot accept negative index" << endl;
            }
        } //End of delete_link


                //-----Printing and saving:

        void output_list ( void ) {
            if( length != 0) {
                node *curr;
                curr = head;
                //
                for( int index = 0; index < length ; index += 1)  {
                    cout << curr->data << endl;
                    curr = curr->link;
                }
            }
            else {
                cout << "No data to print" << endl;
            }
        } //End of print list

        void output_list( char file_name[] ) {
            if( length != 0) {
                ofstream DataFile;;
                DataFile.open( file_name );
                //
                node *curr;
                curr = head;
                //
                for( int index = 0; index < length ; index += 1)  {
                    cout << curr->data << endl;
                    //
                    DataFile << curr->data << "\n";
                    curr = curr->link;
                }
                DataFile.close();
            }
            else {
                cout << "No data to print and save" << endl;
            }
        } //End of output_list

}; //End of class



//Main function:
int main()
{
    //---- Linked list 
    cout << "-- Part 2: Linked list." << endl;
    linked_list listA;

    //#1: Create a list of the following elements:
    //    [11,10,9,8,7,6,5,4,3,2,1]
    listA.insert_node(11, 0);
    listA.insert_node(10, 1);
    listA.insert_node(9, 2);
    listA.insert_node(8, 3);
    listA.insert_node(7, 4);
    listA.insert_node(6, 5);
    listA.insert_node(5, 6);
    listA.insert_node(4, 7);
    listA.insert_node(3, 8);
    listA.insert_node(2, 9);
    listA.insert_node(1, 10);

    //#2: Delete element #5 (counting from 0):
    listA.delete_link(5);

    //#3: Insert element 100 at position 8 (counting from 0):
    listA.insert_node(100, 8);

    return 0;
}

