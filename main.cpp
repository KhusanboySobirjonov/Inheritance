#include <iostream>
using namespace std;
//Kompyuter nomli class yaratildi yani base class
class Kompyuter {
    public:
        int cpu_chastotasi, yadro_num, ram, rom;
        float price;
        //Narx nomli narxni hisoblovchi virtual metod yaratildi
        virtual float Narx () {
            if (cpu_chastotasi==2000 && yadro_num>=2 && ram>=2048 && rom==320) {
                price=cpu_chastotasi*yadro_num/100+ram/80+rom/20;
            }
            return price;
        }
        //Yaroqlilik nomli mantiqiy tur qaytaruvchi virtual metod yaratildi
        virtual bool Yaroqlilik () {
            if (cpu_chastotasi==2000 && yadro_num>=2 && ram>=2048 && rom>=320) {
                return true;
            }
            else {
                return false;
            }
        }
        //Print nomli ma'lumotlarni chop etuvchi metod yaratildi
        void Print () {
             cout << "Protsessor chastotasi: " << cpu_chastotasi << " MHz" << endl;
             cout << "Yadro soni: " << yadro_num << " ta" << endl;
             cout << "Operativ xotira hajmi: " << ram << " Mb" << endl;
             cout << "Qattiq disk hajmi: " << rom << " Gb" << endl;
             cout << "Narxi: " << Narx() << " $" << endl;
             cout << "Ehtiyojlarimiz uchun yaroqliligi: ";
             if (Yaroqlilik()==1) {
                cout << "yaroqli" << endl;
             }
             else {
                cout << "yaroqsiz" << endl;
             }
        }
};
//Noutbuk nomli class yaratildi yani derived class
class Noutbuk : public Kompyuter {
    public:
        int battery;
        float Narx() override {
            if (cpu_chastotasi==2000 && yadro_num>=2 && ram>=2048 && rom==320) {
                price=cpu_chastotasi*yadro_num/100+ram/80+rom/20+battery*10;
            }
            return price;
        }
        bool Yaroqlilik() override {
            if (cpu_chastotasi==2000 && yadro_num>=2 && ram>=2048 && rom>=320 && battery>=240) {
                return true;
            }
            else {
                return false;
            }
        }
};
int main() {
	Kompyuter obj1;
	Noutbuk obj2;
	cout << "***************************\n*     -> KOMPYUTER <-     *\n***************************\n\n";
	obj1.cpu_chastotasi=2000;
	obj1.yadro_num=3;
	obj1.ram=3072;
	obj1.rom=320;
	obj1.Print();
	cout << "\n---------------------------\n\n\n";
	cout << "*************************\n*     -> NOUTBUK <-     *\n*************************\n\n";
	obj2.cpu_chastotasi=2000;
	obj2.yadro_num=4;
	obj2.ram=4096;
	obj2.rom=320;
	obj2.battery=260;
	obj2.Print();
	cout << "\n-------------------------";
	return 0;
}
