#include<bits/stdc++.h>
#include <conio.h>
using namespace std;
int n;
//Tham Lap Phong 20215449
struct Monhoc{
    string MaMH;
    int sotinchi;
    int sotinchiLT;
    int sotinchiBT;
    int sotinchiTH;
    double sotinchihocphi=0;
    double hocPhiPhaiNopCuaMonHoc;
    string Loaigio;

};
struct Hocvien{
    int Mahv;
    string hotenHv;
    int somonhoc;
    double sotienhoc;
    double sotienhoc1tinchi;
    double sotiendanop;
    double sotienhocphaidong;
    Monhoc MH[100];
};
Hocvien HV[100];

void infor1(){
	cout << "Ban da chon nhap ds sinh vien!"<< endl;
            for(int i=1;i<=n;i++){
                double tong = 0;
                cout <<"Nhap thong tin cua sinh vien thu " << i << " : "<<endl;
                cin.ignore();
                cout <<"    Ten sinh vien : " ; getline(cin,HV[i].hotenHv) ; cout << endl;
                cout <<"    So mon hoc : " ; cin >> HV[i].somonhoc; cout << endl;
                cout <<"    So tien mot tin chi : " ; cin >> HV[i].sotienhoc1tinchi;
                for(int j=1;j<=HV[i].somonhoc ; j++){

                    cout << "  Mon hoc thu " << j << endl;
                    cout << "  Ma mon hoc :" ; cin >> HV[i].MH[j].MaMH ;
                    cout << "     So tin chi : " ;cin>> HV[i].MH[j].sotinchi;
                    cout << "     Nhap tin chi LT : ";cin >>  HV[i].MH[j].sotinchiLT; cout << endl;
                    cout << "     Nhap tin chi BT : ";cin >>  HV[i].MH[j].sotinchiBT; cout << endl;
                    cout << "     Nhap tin chi TH : ";cin >>  HV[i].MH[j].sotinchiTH; cout << endl;
                    HV[i].MH[j].sotinchihocphi = HV[i].MH[j].sotinchiLT + HV[i].MH[j].sotinchiBT + HV[i].MH[j].sotinchiTH*1.5;
                    cout <<" Tin chi hoc phi: " << HV[i].MH[j].sotinchihocphi << endl;
                    HV[i].MH[j].hocPhiPhaiNopCuaMonHoc = HV[i].MH[j].sotinchihocphi*HV[i].sotienhoc1tinchi;
                    tong +=  HV[i].MH[j].sotinchihocphi;
                    if((HV[i].MH[j].sotinchiLT>=1)&&(HV[i].MH[j].sotinchiBT>=1)&&(HV[i].MH[j].sotinchiTH)>=1){
                        HV[i].MH[j].Loaigio = "LT-BT-TN";
                    }
                    if((HV[i].MH[j].sotinchiLT==0)&&(HV[i].MH[j].sotinchiBT>=1)&&(HV[i].MH[j].sotinchiTH)>=1){
                        HV[i].MH[j].Loaigio = "BT-TN";
                    }
                    if((HV[i].MH[j].sotinchiLT>=1)&&(HV[i].MH[j].sotinchiBT==0)&&(HV[i].MH[j].sotinchiTH)>=1){
                        HV[i].MH[j].Loaigio = "LT-TN";
                    }
                    if((HV[i].MH[j].sotinchiLT>=1)&&(HV[i].MH[j].sotinchiBT>=1)&&(HV[i].MH[j].sotinchiTH)==0){
                        HV[i].MH[j].Loaigio = "LT-BT";
                    }
                    if((HV[i].MH[j].sotinchiLT==0)&&(HV[i].MH[j].sotinchiBT==0)&&(HV[i].MH[j].sotinchiTH)==3){
                        HV[i].MH[j].Loaigio = "DAMH";
                    }
                    if(HV[i].MH[j].sotinchi==6){
                        HV[i].MH[j].Loaigio = "DATN Cu Nhan";
                    }
                    if(HV[i].MH[j].sotinchi==12){
                        HV[i].MH[j].Loaigio = "DATN Ky Su";
                    }

                }
                cout << "  Hoc phi da nop : " ; cin >> HV[i].sotiendanop;
                HV[i].sotienhocphaidong = tong*HV[i].sotienhoc1tinchi;
            }

}
void infor2(){
	cout << "Ban da chon xuat DS sinh vien, !" << endl;
            cout << "____________________________________________________________________________________" << endl;
            for(int i=1;i<=n;i++){

                cout <<"Ten sv : " << HV[i].hotenHv << endl;
                cout <<"So mon hoc : " << HV[i].somonhoc << endl;
                cout <<"Phai nop : " << HV[i].sotienhocphaidong << endl;
                cout <<"Da nop dot 1 : " << HV[i].sotiendanop << endl;
                if (HV[i].sotienhocphaidong > HV[i].sotiendanop ){
                			cout <<"So tien thieu : " << HV[i].sotienhocphaidong - HV[i].sotiendanop << endl;
                	}
                else if (HV[i].sotienhocphaidong < HV[i].sotiendanop ){
                			cout <<"So tien thua: " << HV[i].sotiendanop - HV[i].sotienhocphaidong << endl;
				
				}
				else if (HV[i].sotienhocphaidong == HV[i].sotiendanop){
							cout <<"Da nop du" << endl;
				}
                cout <<"Tinh trang nop HP : " ;
                if (HV[i].sotienhocphaidong > HV[i].sotiendanop ){
                			cout <<"con thieu"<< endl;
                	}
                else if (HV[i].sotienhocphaidong < HV[i].sotiendanop ){
                			cout <<"Nop thua"<< endl;
				
				}
				else if (HV[i].sotienhocphaidong == HV[i].sotiendanop){
							cout << "Nop du"<< endl;
				}
                cout << "Chi tiet cac mon hoc : " << endl;
                cout << "Ma MH             Loai gio            Khoi luong               Hoc phi phai nop" << endl;
                for(int j=1;j<=HV[i].somonhoc;j++){
                    cout << HV[i].MH[j].MaMH ; cout << "             ";
                    cout << HV[i].MH[j].Loaigio; cout << "            ";
                    cout << HV[i].MH[j].sotinchi <<"("<<HV[i].MH[j].sotinchiLT<<"-"<<HV[i].MH[j].sotinchiBT<<"-"<<HV[i].MH[j].sotinchiTH<<"-"<<HV[i].MH[j].sotinchi*2<<")"; cout <<"                  ";
                    cout << HV[i].MH[j].hocPhiPhaiNopCuaMonHoc << endl;
                }
                cout << "____________________________________________________________________________________" << endl;

            }
}
int main(){
    cout << " Tham Lap Phong - 20215449 - 2022.2 - 727637 " << endl;
    cout << " Nhap so sinh vien : ";
    cin >> n;
    bool flag =1;
    while(flag){
        cout << "** CHUONG TRINH QUAN LY HOC PHI **" << endl;
        cout << "**1. Nhap cac sinh vien, va mon hoc   **" << endl;
        cout << "**2. In ds sinh vien va hoc phi cac mon**" << endl;
        cout << "**0. Thoat                             **" << endl;
        cout << "*****************************************" << endl;
        cout << "**      Nhap lua chon cua ban     **" << endl;
        int k;
        cin >> k;
        switch(k){
        case 1:{
        	cout << "Tham Lap Phong - 20215449 - 2022.2 - 727637 " << endl;
        	cout << " " << endl;
        	infor1();
            break;
        }
        case 2:{
            infor2();
            break;
        }
        case 0 :{
        	flag = 0;
            break;

        }
    }
    if (flag){
    int tmp;
    cout <<"Bam mot so bat ky de tiep tuc!"<<endl;
    cin>>tmp;
    }
	else{
		cout<<" Tham Lap Phong - 20215449 - 2022.2 - 727637 "<<endl;
		cout<<"Ban da chon thoat chuong trinh!"<<endl;
	}
    }
	return 0;  
}

