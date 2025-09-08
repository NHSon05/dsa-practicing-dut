#include <iostream>
#include <string>
using namespace std;

struct Con_nguoi
{
    Con_nguoi(string ht,int t, float v1, float cc)
    {
        ho_ten = ht;   
        tuoi = t;
        vong_mot = v1;
        chieu_cao = cc; 
        con_zin = true;
    }
    int tuoi;
    float vong_mot;
    float chieu_cao;
    string ho_ten;
    bool con_zin;
};

void pha_zin(Con_nguoi *nguoi) // nguoi = hoi_phu_nu[3]
{
    cout << "Thuc hien pha zin: " << (*nguoi).ho_ten << endl;
    (*nguoi).con_zin = false;
}

int main() 
{
    Con_nguoi hoi_phu_nu[5] = 
    {
        Con_nguoi("Thao",22,45,1.25),
        Con_nguoi("Lan",42,45,1.45),
        Con_nguoi("Huong",42,95,1.75),
        Con_nguoi("My",17,95,1.75),
        Con_nguoi("Ha",14,95,1.75)

    };

    cout << "Truoc khi pha em " << hoi_phu_nu[3].ho_ten << (hoi_phu_nu[3].con_zin ? ": Con Zin" : ": Mat zin") << endl;    

    pha_zin(&hoi_phu_nu[3]);
    cout << "Sau khi pha em " << hoi_phu_nu[3].ho_ten << (hoi_phu_nu[3].con_zin ? ": Con Zin" : ": Mat zin") << endl;    


    return 0;
}
