#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
 class qly_hanghoa{
        private:    string tensp;
                    vector<pair<string,float>> sanpham;  
                    int n,soluong;
                    float giatien; 
                    vector<string> dsten;
                    vector<float> dsmoney; 
        public:    
        //tao giao dien san pham danh cho quan ly cua hang:
              void menusp(){
                  do{   cout<<"________________________"<<endl;
                        cout<<"|----MENU HANG HOA:----|"<<endl;
                        cout<<"|1.Themsanpham!        |"<<endl;     //dùng để nhập sản phẩm bán
                        cout<<"|2.Xoasanpham!         |"<<endl;     //dùng để xóa sản phẩm ra khỏi danh sách
                        cout<<"|3.Thoat!              |"<<endl;     //dùng để thoát khỏi menu sản phẩm
                        cout<<"|4.Danh sach san pham! |"<<endl;     //in ra danh sách sản phẩm đã nhập
                        cout<<"|======================|"<<endl;
                        cout<<"|Lua chon cua ban la:";
                        cin>>n;
                        menusp1();
                       
                    } while(n != 3); 
                      for(auto hd : sanpham){      //vòng lặp này dùng để lưu trữ danh sách tên sp và giá tiền vào 2 vector riêng để dùng cho class khách hàng!
                                dsten.push_back(hd.first);
                                dsmoney.push_back(hd.second);
                            } 
                  
                }
        //giao dien sau khi chon cac chuc nang quan ly hang hoa:
              void menusp1(){
                  //lua chon 1:
                  int j=0;
                      if (n == 1){
                         cout<<"Nhap so luong san pham: ";
                         cin>>soluong;
                         for(int i=0; i < soluong; i++){
                            cout<<"Nhap ten mat hang thu("<<i+1<<"):";
                            cin.ignore();
                            getline(cin,tensp);
                            cout<<"Gia san pham: ";
                            cin>>giatien;
                            pair<string,float> sp(tensp,giatien);   //tạo sp kiểu pair để lưu trữ cặp dữ liệu string và float.
                            sanpham.push_back(sp);                  //đẩy dữ liệu vào cuối vector sanpham, vector sanpham kiểu dữ liệu pair.
                          }
                         
                      }
                     
                  //lua chon 2:
                      if (n == 2){
                         if(sanpham.empty()) {
                          cout<<"Khong co san pham de xoa!"<<endl;
                         } else {sanpham.pop_back();
                                 //dsten.pop_back();
                                 //dsmoney.pop_back();  
                         
                            }
                      } 
                  //lua chon 4: 
                      if (n == 4){
                        if(sanpham.empty()) cout<<"Danh sach trong!"<<endl;
                           else {cout<<"_____________________________________"<<endl;
                                 cout<<"|_____ _Danh_sach___san_pham________|"<<endl;
                                 cout<<"|stt |  ten san pham    | gia'(VND) |"<<endl;
                           for(auto hd: sanpham){
                                 cout<<"|"<<setw(4)<<left<<j+1<<"|"<<setw(18)<<hd.first<<"|"<<setw(11)<<right<<hd.second<<"|"<<"\n";
                                 j+=1;
                           }
                                 cout<<"_____________________________________"<<endl;
                         }                
                      }
              }
friend class cty_doanhthu; 
friend class kh_bill;                  

 };

//giao diện dành cho khách hàng
class kh_bill{
private: vector<string> kh_ten;
         float tongtien;
         vector<string> ds_chon;
         int a,b,kh_chon,kh_soluong;
         vector<int> sp_chon,sl;
       
public: 
        kh_bill(){
            tongtien = 0;
        }
        void menukh(qly_hanghoa &hh){
            do{
                        cout<<"________________________"<<endl;
                        cout<<"|---MENU KHACH HANG:---|"<<endl;
                        cout<<"|1.Dat hang!           |"<<endl;  
                        cout<<"|2.In bill !           |"<<endl; 
                        cout<<"|3.thoat!              |"<<endl;     
                        cout<<"|======================|"<<endl;
                        cout<<"|Lua chon cua ban la: ";
                        cin>>a;
                        cout<<"________________________"<<endl;
                        menukh1(hh);
                        
                        
             } while (a != 3);
        }

    void menukh1(qly_hanghoa &hh){
         int stt1=0;
         if(a == 1){
          string name;
              cout<<"-Nhap ten khach hang: ";
              cin.ignore();
              getline(cin,name);
              kh_ten.push_back(name);
              cout<<"_-----------------------_"<<endl;
              cout<<"| #Danh sach san pham:  |"<<endl;
              for(int i=0; i < hh.dsten.size(); i++)  {
                 cout<<"|("<<i+1<<")."<<setw(19)<<left<<hh.dsten[i]<<"|"<<"\n";
              }
              cout<<"|(0).Nhap so 0 de thoat!|"<<endl;
               sp_chon.clear();
               sl.clear();
               do{
                 do{
                  cout<<"-San pham bạn muốn mua(theo DS):";
                  cin>>kh_chon;} while (kh_chon < 1 ||kh_chon > hh.sanpham.size());

                  if(kh_chon == 0) break;

                  cout<<"______________________"<<endl;
                  cout<<"Nhap so luong mua: ";
                  cin>>kh_soluong;

                  sp_chon.push_back(kh_chon-1);
                  sl.push_back(kh_soluong);

                  tongtien = tongtien + (kh_soluong * hh.dsmoney[kh_chon-1]);
                  cout<<"______________________"<<endl;
               } while(kh_chon != 0);
         }


            if(a == 2){
                 cout<<"_____________________________________________"<<endl;
                 cout<<"|            HOA DON  THANH TOAN            |"<<endl;
                 cout<<"|+++++++++++++++++++++++++++++++++++++++++++|"<<endl;
                 cout<<left<<"| Ten khach:"<<kh_ten.back()<<endl;
                 cout<<"| Danh sach san pham da chon: "<<endl;
                 cout<<"---------------------------------------------"<<endl;
                 cout<<"|    ten san pham     | gia tien | so luong |"<<endl;
                    int i=0;
                 for(auto lc: sp_chon){
                   cout<<"|"<<setw(21)<<left<<hh.dsten[lc]<<"|"<<setw(10)<<left<<hh.dsmoney[lc]<<"|"<<setw(10)<<right<<sl[i]<<"|"<<endl;
                   i+=1;
                    }
                     cout<<"_____________________________________________"<<endl;
                     cout<<"Tong tien khach can thanh toan: "<<fixed<<setprecision(0)<<tongtien<<endl;               
         } 

    }
};

class cty_doanhthu{
       private: 
       public:     
};


int main(){
    qly_hanghoa hh;
    kh_bill kh;
    hh.menusp();
    kh.menukh(hh);
    return 0;
}