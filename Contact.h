#include<cstring>
#include<iostream>
#include<fstream>

using namespace std;

class Contact {
    int id;
    char name[40];
    char email[40];
    char mobile[12];
    char fbID[40];
    char address[100];

    public:
    // Default Constructor
    Contact () {

    }

    // Parameterized constructor

    Contact(int cid, const char* cname, const char *cemail, const char* cmobile, const char* cfbID, const char* caddr) {

        id = cid;
        strcpy(mobile,cmobile);
        strcpy(name,cname);
        strcpy(fbID,cfbID);
        strcpy(email,cemail);
        strcpy(address,caddr);
    }
    
    void disp () {
        cout<<endl;
    	cout<<"ID: "<<id<<endl;
    	cout<<"Name: "<<name<<endl;
    	cout<<"Address: "<<address<<endl;
    	cout<<"email: "<<email<<endl;
    	cout<<"mobile: "<<mobile<<endl;
    	cout<<"Facebook ID: "<<fbID<<endl;
    	cout<<"================================================\n";
	}

    friend void search (int id);
    friend void deleteRecord (int id);
};


void addContact (Contact c) {

    // Creating file
    ofstream fout("contacts.dat", ios::app);

    // Add contacts to the file
    fout.write((char*)&c, sizeof(c));
    fout.close();
    cout<<"Contact added succesffuly!"<<endl;
}


void dispAll () {
    Contact temp;
    ifstream fin("contacts.dat"); // Read file
    while(1) {
        fin.read((char*)&temp,sizeof(temp));
        if(fin.eof()) { // If End Of File, then break loop
            break;
        }
        else {
            temp.disp();
        }
    }
}

void search (int id) {
    // For searching a ID we need to read the file
    ifstream fin("contacts.dat");
    Contact temp;
    while(1) {
        fin.read((char*)&temp,sizeof(temp));
        if(fin.eof() == true) {
            break;
        }
        if(temp.id == id) {
            cout<<"Record Found: "<<endl;
            temp.disp();
        }
    }
}

// For Deleting:-
// 1. Get id of record
// 2. Copy all other records to another file temp file except the record which is to be deleted
// 3. Once all record copied, delete original file

void deleteRecord(int id) {
    ifstream fin("contacts.dat");
    ofstream fout("temp.dat");

    Contact obj;

    while(1) {
        fin.read((char*)&obj, sizeof(obj));
        if(fin.eof()) {
            break;
        }
        else {
            if(obj.id != id) {
                fout.write((char*)&obj, sizeof(obj));
            }
        }
    }
    fin.close();
    fout.close();
    remove("contacts.dat");
    rename("temp.dat", "contacts.dat");
}
