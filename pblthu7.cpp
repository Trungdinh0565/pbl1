#include<iostream>
#include<vector>
#include<string>
#include<utility>
using namespace std;
 class thucdon{
        private:    string tensp;
                    vector<pair<string,float>> sanpham;
                    int n,soluong;
                    float giatien;                   
        public:
              void menusp(){
                  do{ 
                        cout<<"-----vui long chon yeu cau:-----"<<endl;
                        cout<<"1.nhapsanpham!"<<endl;
                        cout<<"2.xoasanpham!"<<endl;
                        cout<<"3.thoat!"<<endl;
                        cout<<"lua chon cua ban la: ";
                        cin>>n;
                        menusp1();
                        xuat_hoadon();
                    } while(n != 3); 
                }
              void menusp1(){
                      if (n == 1){
                         cout<<"nhap so luong san pham: ";
                         cin>>soluong;
                         for(int i=0; i < soluong; i++){
                            cout<<"nhap ten mat hang thu("<<i+1<<"):";
                            cin.ignore();
                            getline(cin,tensp);
                            cout<<"gia san pham: ";
                            cin>>giatien;
                            pair<string,float> sp(tensp,giatien);
                            sanpham.push_back(sp);  
                          }
                           cout<<endl;
                      }
              }     
              void xuat_hoadon(){
                if(n==1){
                     cout<<"thong tin hoa don: "<<endl;
                        for(const auto&hd : sanpham){
                           cout<<hd.first<<" "<<hd.second<<"VND"<<endl;
                        }
                 }
               }
                    
};





int main(){
    thucdon tdon;
    tdon.menusp();
    return 0;
}