
#include <iostream>
#include <string.h>
#include <fstream>
#include <assert.h>
using namespace std;
class registration {
private:
    int rno;

public:
    registration()
    {
        rno = 1000;
    }
    void add_rno(int x)
    {
        rno = rno + x;
    }
    int ret_rno()
    {
        return rno;
    }
};
class node {
public:
    string name, book, author;
    node* next;
    node(string n, string b, string a)
    {
        name = n;
        book = b;
        author = a;
        next = NULL;
    }
};
class link {
public:
    ofstream fout;
    node *head, *tail;
    registration R;

public:
    link()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(string name, string book, string author)
    {
        node* p = new node(name, book, author);
        if (head == NULL) {
            head = tail = p;
        }
        else {
            tail->next = p;
            tail = p;
        }
    }
    int search(string book)
    {
        node* p = head;
        while (p != NULL) {
            if (p->book == book) {
                output();
            }
            else {
                p = p->next;
            }
        }
    }
    void deletenode(string book)
    {
        node* p = head;
        while (p != NULL) {
            if (p->book == book) {
                free(p);
            }
            p = p->next;
        }
    }
    void deletelist()
    {
        node* p = head;
        while (p != NULL) {
            head = p->next;
            free(p);
            p = head;
        }
    }
    void print()
    {
        node* p = head;
        fout.open("Library.txt", ios::app);
        if (head == NULL)
            cout << "NO RECORD" << endl;
        else {
            while (p != NULL) {
                fout << "Member Name: " << p->name << endl;
                fout << "Book Name: " << p->book << endl;
                fout << "Author Name: " << p->author << endl;
                fout << "Reigstration No: " << R.ret_rno() << endl;
                p = p->next;
            }
        }
        fout.close();
    }
    void output()
    {
        node* p = head;
        string line;
		ifstream myfile ("Library.txt");
		 
	
        if (head == NULL)
            cout << "NO RECORD" << endl;
        else {
            while (p != NULL) 
				{
					if (myfile.is_open())
			{
				while ( getline (myfile,line) )
					{
					cout << line << '\n';
					}
    		myfile.close();
  			}
			else cout << "Unable to open file"<<endl;
                cout << "Member Name: " << p->name << endl;
                cout << "Book Name: " << p->book << endl;
                cout << "Author Name: " << p->author << endl;
                cout << "Registration no: " << R.ret_rno() << endl;
                p = p->next;
            	}
        	}	
    }
};
main()
{
    registration R;
    link lib;
    int x, y;
    string name, book, author;
    bool cond;
    do {
        cout << "Library Management System" << endl;
        cout << "Enter 1 to insert a book: " << endl;
        cout << "Enter 2 to delete all record " << endl;
        cout << "Enter 3 to see records: " << endl;
        cout << "Enter 4 to search a record: " << endl;
        cout << "Enter 5 exit: " << endl;
        cin >> x;
        cond = true;
        switch (x) {
        case 1:
            cin.ignore();
            cout << "Enter name: " << endl;
            getline(cin, name);
            cout << "Enter book name: " << endl;
            getline(cin, book);
            cout << "Enter author: " << endl;
            getline(cin, author);
            lib.insert(name, book, author);
            R.add_rno(10);
            break;
        case 2:
            lib.deletelist();
            break;
        case 3:
            lib.output();
            lib.print();
            break;
        case 4:
            system("cls");
            cout << "Enter the book name you want to search: " << endl;
            getline(cin, book);
            lib.search(book);
            do {
                cin.ignore();
                cout << "Enter 1 to delete the book: " << endl;
                cout << "Enter 2 to exit: " << endl;
                cin >> y;
                cond = true;
                switch (y) {
                case 1:
                    lib.deletenode(book);
                    break;
                case 2:
                    cond = false;
                    break;
                }
            } while (cond);
            break;
        case 5:
            cond = false;
            break;
        }
    } while (cond);
    system("pause");
}

