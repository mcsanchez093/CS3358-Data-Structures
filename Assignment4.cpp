/* Maria Sanchez 
 * 3/8/17
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


struct listNode
{
    int data;
    listNode *next;
};


void FrontBackSplit(struct listNode* source,struct listNode** frontRef, struct listNode** backRef)
{
    struct listNode* fast;
    struct listNode* slow;

    if (source==NULL || source->next==NULL)
    {
        // length < 2 cases
        *frontRef = source;
        *backRef = NULL;
    }

    else
    {
        slow = source;
        fast = source->next;

        // Advance 'fast' two nodes, and advance 'slow' one node
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // 'slow' is before the midpoint in the list, so split it in two
        //at that point.
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

struct listNode* SortedMerge(struct listNode* a, struct listNode* b)
{
    struct listNode* result = NULL;

    // Base cases
    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);

    // Pick either a or b, and recur
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }

    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}

// sorts the linked list by changing next pointers (not data)
void MergeSort(struct listNode** headRef)
{
    struct listNode* head = *headRef;
    struct listNode* a;
    struct listNode* b;

    // Base case -- length 0 or 1
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    // Split head into 'a' and 'b' sublists
    FrontBackSplit(head, &a, &b);

    // Recursively sort the sublists
    MergeSort(&a);
    MergeSort(&b);

    // answer = merge the two sorted lists together
    *headRef = SortedMerge(a, b);
}

void display(listNode* node)
{
    if(node == NULL)
        return;
    else
        display(node->next);

    cout<<node->data<<" ";
}
//********************************************************
//  Main
//********************************************************

int main()
{
    bool check = true;
    bool dblCheck = true;

    while(check && dblCheck)
    {
    cout << endl;
    cout << "Welcome to Maria's Linked list manipulation program\n";

    listNode *head;
    label :
    head = NULL;

    // Populate original LL - 19 random values between 10 and 20
    for(int i = 0; i < 19; i++)
    {
        int r = rand()%10;
        r += 10;

        // Connecting the LL
        struct listNode* new_Node = (struct listNode*) malloc(sizeof(struct listNode));
        new_Node->data  = r;

        if(head == NULL)
        {
            head = new_Node;
            head->next = NULL;
        }
        else
        {
            new_Node->next = head;
            head = new_Node;
        }
    }

    MergeSort(&head);

    // INITIAL PRINT
    cout << endl;
    cout << "Sorted main list of 19 random integer numbers that are between 10 and 20 are as follows :\n";

    listNode *node;
    node = head;
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }

    // Insert -100 at beginning of LL & Print LL
    cout << endl;
    cout << endl;
    cout << "Main list after inserting the new number -100 at the beginning :\n";

    struct listNode *new_node1 = (struct listNode*) malloc(sizeof(struct listNode));

    new_node1->data = -100;
    new_node1->next = head;
    head = new_node1;
    node = head;

    while(node)
    {
        cout << node->data << " ";
        node = node->next;
    }


    // Insert 15 at 3rd location of LL & Print LL
    cout << endl;
    cout << endl;
    cout << "Main list after inserting the new number 15 at third location:\n";

    struct listNode* new_node2 = (struct listNode*) malloc(sizeof(struct listNode));


    new_node2->data = 15;
    node = head;
    node = node->next;
    listNode *node1 = node->next;

    new_node2->next = node1;
    node->next = new_node2;

    node = head;
    while(node)
    {
        cout << node->data << " ";
        node = node->next;
    }

    // Append 1000 at end of LL & Print LL
    cout << endl;
    cout << endl;
    cout << "Main list after appending new number 1000 :\n";
    struct listNode* new_node3 = (struct listNode*) malloc(sizeof(struct listNode));


    new_node3->data = 1000;

    node = head;
    while(node->next)
    {
        node = node->next;
    }
    node->next = new_node3;
    new_node3->next = NULL;

    node = head;
    while(node)
    {
        cout << node->data << " ";
        node = node->next;
    }

    // Remove 5 from LL & Print LL
    cout << endl;
    cout << endl;
    cout << "Main list after removing number 5 :\n";
    cout << endl;
    cout << "Number 5 does not exist in the list\n";

    node = head;
    while(node)
    {
        cout << node->data << " ";
        node = node->next;
    }

    // Remove second element from LL & Print LL
    cout << endl;
    cout << endl;
    cout << "Main list after removing the second element :\n";

    node = head;
    node1 = node->next->next;
    free(head->next);
    node->next = node1;

    node = head;
    while(node)
    {
        cout << node->data << " ";
        node = node->next;
    }


    // Rotate the list 1 to the right & Print LL
    cout << endl;
    cout << endl;
    cout << "Main list after rotating the list one position to the right :\n";

    node = head;
    node1 = node->next;

    while(node1->next)
    {
        node1 = node1->next;
        node = node->next;
    }

    node->next = NULL;
    node1->next = head;
    head = node1;
    node = head;

    while(node)
    {
        cout << node->data << " ";
        node = node->next;
    }


    // Search list for "17" & Print LL & Found / unfound message
    cout << endl;
    cout << endl;
    cout << "Searching the main list for item number 17 :\n";

    node = head;
    int count = 0;

    while(node)
    {
        count++;
        if(node->data == 17)
        {
            cout << endl;
            cout << "Item found at the location :" << count << endl;
            break;
        }
        node = node->next;
    }

    if(!node)
    {
        cout << endl;
        cout << "Item not found in the list ! " << endl;
    }
    // Display LL backwards
    cout << endl;
    cout << "Displaying the main list backward :\n";

    display(head);

    // Split LL into 2 sub lists (First 10 --> sub_List_1) (Last 10 --> sub_List_2)
    listNode *sub_List_1 = NULL;
    listNode *sub_List_2 = NULL;
    node = head;
    count = 1;

    while (count <= 10)
    {

        struct listNode* new_node = (struct listNode*) malloc(sizeof(struct listNode));


        new_node->data  = node->data;
        count++;
        node = node->next;

        if (sub_List_1 == NULL)
        {
            sub_List_1 = new_node;
            sub_List_1->next = NULL;
        }

        else
        {
            node1 = sub_List_1;
            while (node1->next)
            {
                node1 = node1->next;
            }
            node1->next = new_node;
        }

    }

    while(node)
    {
        struct listNode* new_node = (struct listNode*) malloc(sizeof(struct listNode));

        new_node->data  = node->data;
        node = node->next;

        if (sub_List_2 == NULL)
        {
            sub_List_2 = new_node;
            sub_List_2->next = NULL;
        }

        else
        {
            node1 = sub_List_2;
            while (node1->next)
            {
                node1 = node1->next;
            }
            node1->next = new_node;
        }
    }
    cout << endl;
    cout << endl;
    cout << "Splitting the main list into 2 Sublists (sub_List_1 and sub_List_2) : \n ";
    cout << endl;
    cout << "Original List :\n";
    node = head;

    while(node){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
    cout << endl;
    cout << "Sub_List_1 :\n";
    node = sub_List_1;

    while(node)
    {
        cout << node->data << " ";
        node = node->next;
    }

    cout << endl;
    cout << endl;
    cout << "Sub_List_2 :\n";
    node = sub_List_2;

    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }


    // Delete duplicate numbers from LL
    node = head;
    listNode *node2 = NULL;
    while (node->next)
    {
        int x = node->data;
        node2 = node->next;
        node1 = node;

        while (node2)
        {
            if (node2->data == x)
            {
                node1->next = node2->next;
                free(node2);
                node2 = node1->next;
            }

            else
            {
                node1 = node1->next;
                node2 = node2->next;
            }
        }

        if(node->next)
            node = node->next;
    }
    cout << endl;
    cout << endl;
    cout << "Main list after deleting duplicate numbers :\n";
    node = head;
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }
    // Delete the main LL
    cout << endl;
    cout << endl;
    cout << "Delete the entire main list !";

    node = head;
    node1 = node->next;

    while(node1)
    {
        free(node);
        node = node1;
        node1 = node1->next;
    }
    cout<<endl;
    head = NULL;
    // Search main LL for "35" & display found / unfound message
    cout << endl;
    cout << endl;
    cout<<"Searching the main list for item number 35 :\n";
    if(head == NULL)
    {
        cout << endl;
        cout << "List is empty !! \n";
    }

    else
    {
        node = head;
        int count = 0;

        while(node)
        {
            count++;

            if(node->data == 35)
            {
                cout << "Item found at the location :" << count << endl;
                break;
            }
            node = node->next;
        }

        if(!node)
        {
            cout << "Item not found in the list ! " << endl;
        }
    }


    //while(check || dblCheck)
    //{
        check = false;
        dblCheck = false;

        cout << endl;
        cout<<"Would you like to run the program again ?\n";
        cout<<"Enter Y or N  --------> ";
        char c;
        cin >> c;

        if(c == 'Y'||c == 'y'){
            check = true;
            dblCheck = true;
        }
        else if(c == 'N'||c == 'n')
            check = false;
        else
        {
            cout << "\nError ***** Invalid Selection  "<< c <<" - Must enter y|Y or n|N \n\n";
            dblCheck = false;
        }
    //}

    }

    cout << "\nThis LL program is implemeted by Maria Sanchez\nMarch - 2017\n";
}
