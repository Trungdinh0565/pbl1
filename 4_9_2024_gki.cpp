#include<iostream>
#include<iomanip>
using namespace std;
struct hovaten{
  char ho[50];
  char ten[50];
};
struct congnhan{
    hovaten hoten;
    int ngaycong;
    float luong,thunhap;
    float heso;
};

void congdinhmuc( float &congdinhmuc1){
    cout<<"nhap so tien 1 ngay cong: ";
    cin>>congdinhmuc1;
}

void thongtin(congnhan &cn){
cout<<"nhap ho : ";
cin.getline(cn.hoten.ho,50);
cout<<"nhap ten cua cong nhan: ";
cin.getline(cn.hoten.ten,50);
cout<<"nhap so ngay cong: ";
cin>>cn.ngaycong;
cout<<"nhap he so luong: ";
cin>>cn.heso;

}

void luong(congnhan &cn,float &congdinhmuc1){
cn.luong= cn.ngaycong*congdinhmuc1;
}
void thunhap(congnhan &cn){
cn.thunhap=cn.luong*cn.heso;
}

void xuat(congnhan &cn, float &congdinhmuc1){
cout<<"ho va ten cong nhan: "<<cn.hoten.ho<<" "<<cn.hoten.ten<<endl;
cout<<"so ngay lam: "<<cn.ngaycong<<endl;
cout<<"muc luong 1 ngay: "<<congdinhmuc1<<endl;
cout<<"he so luong: "<<cn.heso<<endl;
cout<<"----------------------"<<endl;
cout<<"luong: "<< fixed << setprecision(0) << cn.luong<<endl;
cout<<"thu nhap cua nguoi nay la: "<< fixed << setprecision(0)<< cn.thunhap;

}

int main(){
    float congdinhmuc1;
    congnhan cn;
    thongtin(cn);
     congdinhmuc(congdinhmuc1);
    luong(cn,congdinhmuc1);
    thunhap(cn);
    xuat(cn,congdinhmuc1);
    return 0;
}



