#include "iostream"
#include "fstream"
#include "cstring"
#include "iomanip"

using namespace std;

class phnbk
{
private:
  char name[20];
  long phn;
public:
  void snum();
  void sname();
  void upnum();
}



void phnbk::sname()
{
  fstream f1;
  long phone;
  int ps,i,bo;
  int flag=0;
  ps=-1,i=0;
  cout<<"Enter Phone number:"
  cin>>phone;
  f1.open("Phonebook.dat",ios::in|ios::binary);
  f1.seekg(0,ios::beg);
  while(f1.read((char*)this.sizeof(*this))){
    if(this->phn=phone){
      ps=i;
      flag=1;
      break;
    }
    i++;
  }
  if(flag==1)
  {
    bo=ps*sizeof(*this);
    f1.seekp(bo);
    f1.read((char*)this,sizeof(*this));
    cout<<"Name is:"<<this->name;
  }
  else
  cout<<"No such number";
}

void phnbk::snum()
{
  fstream f1;
  string name1;
  int ps,i,bo;
  int flag=0;
  ps=-1,i=0;
  cout<<"Enter Name:"
  cin>>name1;
  f1.open("Phonebook.dat",ios::in|ios::binary);
  f1.seekg(0,ios::beg);
  while(f1.read((char*)this.sizeof(*this))){
    if(strcmp(this->name,name1)==0){
      ps=i;
      flag=1;
      break;
    }
    i++;
  }
  if(flag==1)
  {
    bo=ps*sizeof(*this);
    f1.seekp(bo);
    f1.read((char*)this,sizeof(*this));
    cout<<"Phonenumber is:"<<this->phn;
  }
  else
  cout<<"No such name";
}

void phnbk::upnum()
{
  fstream f1;
  string name1;
  long phone;
  int ps,i,bo;
  int flag=0;
  ps=-1,i=0;
  cout<<"Enter Name:"
  cin>>name1;
  f1.open("Phonebook.dat",ios::in|ios::binary);
  f1.seekg(0,ios::beg);
  while(f1.read((char*)this.sizeof(*this))){
    if(strcmp(this->name,name1)==0){
      ps=i;
      flag=1;
      break;
    }
    i++;
  }
  if(flag==1)
  {
    bo=ps*sizeof(*this);
    f1.seekp(bo);
    f1.read((char*)this,sizeof(*this));
    cout<<"Current Phonenumber is:"<<this->phn;
    cout<<phone;
    this->phn=phone;
    f1.write((char*)this,sizeof(*this))<<flush;
  }
  else
  cout<<"No such name";
}

int main(void)
{
  int ch;
  phnbk obj;
  while(true)
  {
    cout<<"===================================================================="<<endl;
    cout<<"                 1. Search Name by Phone number"<<endl;
    cout<<"                 2. Serach Phone number by Name"<<endl;
    cout<<"                 3. Update Phone number by Name"<<endl;
    cout<<"                 0. Exit the program"<<endl;
    cout<<"===================================================================="<<endl;
    cout<<"                        Your choice:";
    cin>>ch;
    switch(ch)
    {
      case 1:obj.sname(); break;
      case 2:obj.snum(); break;
      case 3:obj.upnum(); break;
      case 0:break;
      default: cout<<"Wrong choice";
    }
  }
}
