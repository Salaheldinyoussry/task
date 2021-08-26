#include <bits/stdc++.h>
using namespace std;


class Room {
  public:
    float price;
    float dryCleaning;
    float spa;
    float getReservationPrice(int noRooms, int noNights ){
     return noNights*noRooms*price;
    }
};

class Monster : public Room{
   public:
       Monster(){
       price =200;
       dryCleaning=30;
       spa=50;

       }



};
class Human : public Room{
   public:
       Human(){
       price =500;
       dryCleaning=70;
       spa=100;

       }



};

class RoomFactory{
   public:
       Room getRoom(string type){
       if(type=="monster"){
            Monster monster;
        return monster;
       }
       else{
                Human human;
             return  human;

       }
       }
};

class RoomsRepository{
    public:
      int monsterRoomsNo=15;
      int humanRoomsNo=5;
      void increaseRooms(string type,int value){
          if(type=="monster"){
            monsterRoomsNo-=value;
          }
          else{
            humanRoomsNo-=value;

          }
      }
      void decreaseRooms(string type,int value){
         if(type=="monster"){
            monsterRoomsNo+=value;
          }
          else{
            humanRoomsNo+=value;

          }
      }
      int getAvailableRooms(string type ){
        if(type=="monster"){
          return  monsterRoomsNo;
          }
         return humanRoomsNo;
      }

};


class ReservationApi{
public:
    RoomsRepository roomRepo;
    RoomFactory roomFac;

    int generateID (){

     int id= rand();
     return id;
    }

int reserve(int roomsNo , int nightsNo ,string type){

      if(roomsNo>roomRepo.getAvailableRooms(type)){
        return -1;
      }else{
        roomRepo.decreaseRooms(type,roomsNo);
        Room room =roomFac.getRoom(type);
        return   room.getReservationPrice(roomsNo,nightsNo);


      }}

  int extend(int roomsNo , int nightsNo ,string type){
        Room room =roomFac.getRoom(type);
        return   room.getReservationPrice(roomsNo,nightsNo);
    }

    int  additionalServic(string type){

     Room room =roomFac.getRoom(type);
        return  room.dryCleaning+room.spa;


    }
    void cancelReservation(int roomsNo ,string type){
    roomRepo.increaseRooms(type,roomsNo);

    }

};
class User{
public :
    int noRooms=0;
     int id;
     string type;


};

vector <User> v;  // should be stored in files or database or login and logout will be an issue
int main()
{
     // the following is a basic demonstration
    ReservationApi ra;
    User u;
   cout<<"New? Enter 1"<<endl;
   cout<<"Old? Enter 2"<<endl;
   string c;
   cin>>c;
   if(c=="1"){
     string type;
     cout<<"Enter type :"<<endl;
        cin>>type;
        u.id=ra.generateID();
        u.type=type;
            cout<<"your ID : "<<u.id<<endl;


   }
   else if(c=="2"){
     int id;
     cout<<"Enter ID : " <<endl;
     cin>>id;
     bool flag=false;
     for(int i=0; i<v.size(); i++){
        if(v[i].id==id){
            u=v[i];
            flag=true;
            break;
        }

     }
     if(!flag){
        cout<<"Wrong ID"<<endl;
        return 0;
     }

   }

   while (true){
        cout<<"\n";
                cout<<"===========================";

       cout<<"\nnew Reservation? Enter 1 noRooms noNights "<<endl;
   cout<<"extend? Enter 2 noNights"<<endl;
   cout<<"cancel? Enter 3"<<endl;
   cout<<"additional service? Enter 4"<<endl;

   cout<<"Exit? Enter 5"<<endl;
                  cout<<"===========================\n";

   string option ;

   cin>>option;

   if(option=="1"){
        int r,n;
   cin>>r>>n;
   int cost=ra.reserve(r,n,u.type);
   if(cost==-1){
   cout<<"\n no available rooms: "<<endl;

   }
   else{
   cout<<"\n cost: "<<cost<<endl;
   }
   }
   else if(option=="2"){
             int n;
   cin>>n;

      int cost=ra.extend(u.noRooms,n,u.type);

   cout<<"\n cost: "<<cost<<endl;

   }
 else if(option=="3"){

   ra.cancelReservation(u.noRooms,u.type);
   cout<<"\n Reservation has been canceled";
   }
    else if(option=="4"){
    cout<<"\n cost: "<<ra.additionalServic(u.type);
   }
     else if(option=="5"){
      break;
   }
    else {
    cout<<"Wrong Value"<<endl;
   }



   }


    return 0;
}
