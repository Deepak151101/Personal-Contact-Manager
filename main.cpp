#include "Contact.h"

// Contact(int cid, char* cname, char *cemail, unsigned long cmobile, char* cfbID, char* caddr)

int main (int argc, char** argv) {
//	Contact c1(1,"Ajay","ajay@gmail.com", "9576145237", "fb.com/abk", "Kolhapur");
//	c1.disp();
//	
//	Contact c2(2,"Arun","arun@gmail.com", "9416145237", "fb.com/ard", "Pune");
//	c2.disp();


    // Giving users choice
    while(1) {
        int ch;
        cout<<"Select choice: " <<endl;
        cout<<"\n1. Add Contact \n2. Display All \n3. Search Contact \n4. Delete Contact \n5. Exit \n" <<endl;

        cin>>ch;

        switch(ch) {
            case 1: 
                {
                    int id;
                    char name[50],email[50],phone[11], fb[50],city[40];
                    cout<<"Enter ID: ";
                    cin>>id;

                    cout<<"Enter name: ";
                    cin>>name;

                    cout<<"Enter Email: ";
                    cin>>email;

                    cout<<"Enter Phone: ";
                    cin>>phone;

                    cout<<"Enter fb ID: ";
                    cin>>fb;
                    
                    cout<<"Enter City: ";
                    cin>>city;

                    Contact c1(id,name,email,phone,fb,city);
                    addContact(c1);
                }
            break;

            case 2:
                {
                    dispAll();
                }
                break;

            case 3:
                {
                    int id;
                    cout<<"Enter the id you need to search"<<endl;
                    cin>>id;
                    search(id);
                }
                break;

            case 4:
                {
                    int id;
                    cout<<"Enter the id you need to be deleted"<<endl;
                    cin>>id;
                    deleteRecord(id);

                }
            break;

            case 5:
                {
                    exit(0);
                }

        }
    }


	

    return 0;
}



