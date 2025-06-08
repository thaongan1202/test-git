
/*
HỌ VÀ TÊN: PHẠM THỊ THẢO NGÂN
NGÀY CẬP NHẬT: 11/03/2025
MỤC ĐÍCH:  BÀI TẬP STRUCT ********(BASIC)**********
YÊU CẦU : CẤU TRUC SINH VIÊN
   THÔNG TIN CỦA SINH VIÊN BAO GỒM:
        MÃ SINH VIÊN
        TÊN SINH VIÊN
        TÊN LỚP
        NGÀY SINH
        ĐIỂM GPA LÀ SỐ THỰC HỆ 4
        XÂY DỰNG CHƯƠNG TRÌNH THỰC HIỆN CÁC YÊU CẦU SAU:
    1. THÊM MỚI 1 SINH VIÊN VÀO DANH SÁCH
    2. HIỂN THỊ TOÀN BỘ DANH SÁCH SINH VIÊN
    3. TÌM KIẾM SINH VIÊN THEO MÃ SINH VIÊN(TÊN, LỚP)
       HIỂN THỊ CÁC SINH VIÊN CÓ MÃ ĐÚNG VỚI MÃ CẦN TÌM HOẶC CHỨA MÃ CẦN TÌM
    4. LIỆT KÊ CÁC SINH VIÊN CÓ ĐIỂM GPA CAO NHẤT
    5. LIỆT KÊ CÁC SINH VIÊN CÓ GPA >=2.5 THEO THỨ TỰ ĐIỂM GIẢM DẦN
    6. SẮP XẾP CÁC SINH VIÊN THEO TÊN
    7. SẮP XẾP SINH VIÊN THEO LỚP, CÁC SINH VIÊN CÙNG LỚP SẼ XẾP THEO TỨ TỰ TÊN TĂNG DẦN
       THEO THỨ TỰ TỪ ĐIỂN, CHÚ Ý SẮP XẾP TÊN TRƯỚC SAU ĐẾN HỌ VÀ TÊN ĐỆM
    8. SẮP XẾP SINH VIÊN THEO LỚP, CÁC SINH VIÊN CÙNG LỚP XẾP THEO THỨ TỰ ĐIỂM GPA GIẢM DẦN
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
struct sinhvien {
    string msv;
    string lop, ns;
    string ten;
    float gpa;
    bool operator > ( const sinhvien &other) const {
        return gpa > other.gpa;
    }
};
void themsv ( sinhvien &p){
    cout << " nhập msv: ";  cin >> p.msv;
    cin.ignore();
    cout << " nhập tên sv: "; getline (cin, p.ten);
    cout << " nhập lớp: "; cin >> p.lop;
    cout << " nhập ngày sinh: "; cin >> p.ns;
    cout << " nhập gpa: "; cin >> p.gpa;
}
void in (sinhvien p){
       cout << "Mã sinh viên: " << p.msv << endl;
       cout << "Tên sinh viên: " <<p.ten << endl;
       cout << "Lớp: " << p.lop<< endl;
       cout << "Ngày sinh: " << p.ns << endl;
       cout << "GPA: " << p.gpa << endl;
        cout << "--------------------------------------\n";
}
void inds ( sinhvien p[], int n){
    cout << "Thông tin danh sách sinh viên: \n";
    for ( int i=0; i<n; i++){
          in(p[i]);
    }
}
//Nếu tìm thấy, find() trả về vị trí xuất hiện đầu tiên của chuỗi con trong chuỗi gốc.
//Nếu không tìm thấy, nó trả về string::npos.
//Nếu bạn muốn kiểm tra xem find() có tìm thấy kết quả hay không, hãy so sánh với string::npos như trên, vì nếu không tìm thấy, nó sẽ trả về string::npos.
void tkma ( sinhvien p[], int n){
    string ma;
    cout << " nhập msv cần tìm: ";
    cin >> ma;
    bool found = false;
    for ( int i=0; i<n; i++)
    {
        if (p[i].msv.find(ma) != string::npos)
        { // tìm thấy
            in(p[i]);
            found = true;
        }
    }
    if ( found == false)
    {
          cout << "Không tìm thấy mã vừa nhập \n";
    }
}
void tklop ( sinhvien p[], int n){
    string lopcantim;
    cout << " nhập lớp muốn tìm: ";
    cin >> lopcantim;
    bool found = false;
    for ( int i=0; i<n; i++)
    {
        if ( p[i].lop.find(lopcantim) != string::npos)
        {
              in(p[i]);
              found = true;
        }
    }
    if ( found == false) cout << " không tìm thấy lớp vừa nhập \n";
}
bool compare ( sinhvien a, sinhvien b){
    return a.gpa > b.gpa;
   } 
void svdiemcaonhat (sinhvien p[], int n){
    cout << " sinh viên có điểm cao nhất là : \n";
    sort ( p, p+n, compare);
    in (p[0]);
}
void svcodiem2 ( sinhvien p[], int n){
    cout << " sinh viên có gpa >=2.5 là : \n";
    vector <sinhvien> v; //  <sinhvien> chứa các phần tử kiểu sinhvien
    for ( int i=0; i<n; i++)
    {
        if ( p[i].gpa >= 2.5) v.push_back(p[i]);
    }
    sort (v.begin(), v.end(), compare);
    for ( sinhvien x : v)
    {
        in(x);
    }
}
// phạm thị thảo ngân: nganphamthithao
// chuẩn hoá chuỗi 
// sử dụng vector vì nó đếm số phần tử được nên lấy hoj tên dễ hơn
string chuanhoa ( string s){
      stringstream ss(s);
      vector <string> v;
      string tmp;
      string res="";
      while ( ss >> tmp){
             v.push_back(tmp);
      }
    res += v[v.size() -1];// thêm tên vào đầu chuỗi mới là res để xét tên trước
    for ( int i=0; i< v.size()-1; i++)
    {
        res+= v[i]; // xong thêm họ và tên đêm vào sau
    }
   return res;
}
bool cmp ( sinhvien a, sinhvien b){
    string ten1= chuanhoa(a.ten);
    string ten2= chuanhoa(b.ten);
   return ten1 < ten2;  
}
void sxten ( sinhvien p[], int n){
      cout << "DANH SÁCH SINH VIÊN SAU KHI ĐƯỢC SẮP XẾP THEO TÊN LÀ: \n ";
      sort (p, p+n, cmp);
      for ( int i=0; i<n; i++) 
      {
        in(p[i]);
      }
}
bool cmp1 ( sinhvien a, sinhvien b){
    string ten1= chuanhoa(a.ten);
    string ten2= chuanhoa(b.ten);
    if ( a.lop != b.lop) return a.lop < b.lop;
    else return ten1 <ten2;
}
void sxlopten (sinhvien p[], int n){
     cout << "DANH SÁCH SINH VIÊN ĐƯỢC SẮP XẾP THEO LỚP (CÙNG LỚP THÌ XẾP THEO TÊN TĂNG DẦN)LÀ: \n ";
     sort (p, p+n, cmp1);
     for ( int i=0; i<n; i++)
     {
        in(p[i]);
     }
}
bool cmp2 (sinhvien a, sinhvien b){
    if ( a.lop != b.lop) return a.lop < b.lop;
    else return a.gpa > b.gpa;
}
void sxlopgpa (sinhvien p[], int n){
     cout << "DANH SÁCH SINH VIÊN ĐƯỢC SẮP XẾP THEO LỚP (CÙNG LỚP THÌ XẾP THEO GPA GIẢM DẦN)LÀ: \n ";
     sort (p, p+n, cmp2);
     for ( int i=0; i<n; i++)
     {
        in(p[i]);
     }
}
void tkten ( sinhvien p[], int n){
    string tencantim;
    cout << " nhập tên sinh viên muốn tìm: ";
    cin.ignore();
    getline ( cin, tencantim);
    bool found = false;
    for ( int i=0; i<n; i++)
    {  
        string timten = chuanhoa(p[i].ten);
        if ( timten.find(tencantim) != string ::npos )
        {
             in ( p[i]);
              found = true;
        }
    }
    if ( found == false) cout << "không tìm thấy tên sinh viên vừa nhập \n ";
}


int main (){
    int n=0; // lưu số sinh viên
    sinhvien a[100];
    while (1)
    {
         cout << " ***************MENU**************** \n ";
         cout << "1.Nhập thông tin sinh viên \n";
         cout << "2.Hiển thị toàn bộ danh sách sinh viên \n";
         cout << "3.Tìm kiếm sinh viên theo mã sinh viên \n";
         cout << "4.Tìm kiếm sinh viên theo lớp \n";
         cout << "5.Tìm kiếm sinh viên theo tên \n";
         cout << "6.Liệt kê sinh viên có điểm gpa cao nhất \n";
         cout << "7.Liệt kê sinh viên có gpa >=2.5 \n";
         cout << "8.Sắp xếp sinh viên theo tên\n";
         cout << "9.Sắp xếp sinh viên theo lớp và tên\n";
         cout << "10.Sắp xếp sinh viên theo lớp và gpa\n";
         cout << "0.Thoát! \n";
         cout << "*************************************\n";
        int lc;
        cout << "VUI LÒNG NHẬP LỰA CHỌN: ";
        cin >> lc;
        if ( lc == 1)
        {
            themsv(a[n]);
            ++n;
        }
        else if ( lc == 2)
        {
            inds(a,n);
        }
        else if (lc == 3)
        {
            tkma(a,n);
        }
        else if (lc == 4)
        {
            tklop(a,n);
        }
        else if (lc ==5)
        {
            tkten(a,n);
        }
        else if (lc == 6)
        {
            svdiemcaonhat(a,n);
        }
        else if (lc == 7)
        {
            svcodiem2(a,n);
        }
        else if (lc == 8)
        {
             sxten(a,n);
        }
        else if (lc == 9)
        {
            sxlopten(a,n);
        }
        else if (lc == 10)
        {
            sxlopgpa(a,n);
        }
        else if (lc == 0)
        {
            return 0;
        }
    }
}