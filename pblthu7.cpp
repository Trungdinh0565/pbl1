#include<iostream>
#include<vector>
#include<string>
using namespace std;
 class thucdon{
        private:    string tensp;
                    vector<pair<string,float>> sanpham;
                    int n,soluong;
                    float giatien;                   
        public:
        //tao giao dien chuc nang san pham cua cua hang:
              void menusp(){
                  do{ 
                        cout<<"-----MENU SAN PHAM:-----"<<endl;
                        cout<<"1.nhapsanpham!"<<endl;            //dùng để nhập sản phẩm bán
                        cout<<"2.xoasanpham!"<<endl;            //dùng để xóa sản phẩm vừa thêm ra khỏi danh sách
                        cout<<"3.thoat!"<<endl;                //dùng để thoát khỏi menu sản phẩm
                        cout<<"4.danh sach san pham!"<<endl;  //in ra danh sách sản phẩm đã nhập
                        cout<<"lua chon cua ban la: ";
                        cin>>n;
                        menusp1();
                       
                    } while(n != 3); 
                }
        //giao dien sau khi chon chuc nang 1sp:
              void menusp1(){
                  //lua chon 1:
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
                    
                       }
                  //lua chon 2:
                      if(n == 2){
                         if(sanpham.empty()) {
                          cout<<"khong co san pham de xoa!"<<endl;
                         } else sanpham.pop_back();
                      } 
                  //lua chon 4: 
                      if (n == 4){
                        if(sanpham.empty()) cout<<"danh sach trong!"<<endl;
                         else { cout<<"danh sach san pham:"<<endl;
                            for(auto &hd: sanpham){
                                cout<<hd.first<<" "<<hd.second<<"VND ";
                            }
                          cout<<endl;
                         }
                      }


              }     
      
              
            
 friend class doanhthu;                   
};


class doanhthu{















};




























int main(){
    thucdon tdon;
    tdon.menusp();
    return 0;
}