#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main(){
    struct Tmark                         //���Գɼ�
	{      float pol;                    //����
           float chn;                    //����
           float eng;                    //Ӣ��
           float com;                    //�����
           float oral;                   //����
	};
    struct Tmarks                        //ӦƸ����Ϣ�Ϳ��Գɼ�
	{       char name[20];               //����
            float Sage;                  //�����
            float Srecord;               //ѧ����
            float Swlen;                 //����������
            Tmark mark;                  //���Գɼ�
            float total;                 //�ܷ�
	};
    struct Tinform                       //ӦƸ�߸�����Ϣ       
{       char name[20];               //����
        char sex;                    //�Ա�
        float age; 	                 //����
		char schoolrecord;           //ѧ��
        float worklen;               //�οƼ��ɲ�����
        char wordsite[60];           //�ֹ�����λ
		Tmark mark;                  //���Գɼ�
};
    Tinform people[50];
	int i,j,num;
	cout<<"ѧ��  ˶ʿ��m��ʾ ��ʿ��d��ʾ ������u��ʾ ������o��ʾ"<<endl;
	cout<<"�Ա� ����m��ʾ Ů��f��ʾ"<<endl;
	cout<<"ӦƸ����Ϊ��"<<endl;
	cin>>num;
	ifstream ifile;
	ifile.open("d:\\ӦƸ�߸�����Ϣ.txt");
	for(j=0;j<num;j++){
		ifile>>people[j].name;
		ifile>>people[j].sex;
		ifile>>people[j].age;
		ifile>>people[j].schoolrecord;
		ifile>>people[j].worklen;
		ifile>>people[j].wordsite;
		ifile>>people[j].mark.pol;
		ifile>>people[j].mark.chn;
   	    ifile>>people[j].mark.eng;
		ifile>>people[j].mark.com;
		ifile>>people[j].mark.oral;
	}
	ifile.close();
    Tmarks altogether[50];
	for(i=0;i<num;i++){
		strcpy(altogether[i].name,people[i].name);
		altogether[i].mark=people[i].mark;
	}
	for(i=0;i<num;i++){
		if(people[i].age>=30&&people[i].age<35) altogether[i].Sage=(people[i].age-30.0)*2+70;
		else if(people[i].age>=35&&people[i].age<40) altogether[i].Sage=(people[i].age-35)*4.0+80;
		else if(people[i].age>=40&&people[i].age<50) altogether[i].Sage=(40-people[i].age)*2.5+100;
		else if(people[i].age>=50&&people[i].age<=55) altogether[i].Sage=(50-people[i].age)*1.0+75;
        else altogether[i].Sage=0;
		if(people[i].worklen>0&&people[i].worklen<=1) altogether[i].Swlen=people[i].worklen*70;
        else if(people[i].worklen>1&&people[i].worklen<=2) altogether[i].Swlen=(people[i].worklen-1)*30+70;
        else if(people[i].worklen>2&&people[i].worklen<=6) altogether[i].Swlen=(6-people[i].worklen)*25+20;
        else altogether[i].Swlen=0;
		if(people[i].schoolrecord=='d') altogether[i].Srecord=100;
        else if(people[i].schoolrecord=='m')altogether[i].Srecord=75;
        else if(people[i].schoolrecord=='u')altogether[i].Srecord=50;
	    else altogether[i].Srecord=0;
		}
	altogether[i].total=altogether[i].Sage+altogether[i].Srecord+altogether[i].Swlen+altogether[i].mark.pol+altogether[i].mark.chn+altogether[i].mark.eng+altogether[i].mark.com+altogether[i].mark.oral*2;
	Tmarks temp;
	bool noswap;
	for(i=0;i<num;i++){
		noswap=true;
		for(j=num-1;j>i;j--){
			if(altogether[j].total>altogether[j-1].total){
				temp=altogether[j];
				altogether[j]=altogether[j-1];
				altogether[j-1]=temp;
				noswap=false;
			}
		}
		if(noswap)break;
	}
	ofstream ofile;
	ofile.open("d:\\�ɼ��ܱ�.txt");
	for(i=0;i<num;i++){
		ofile<<endl;
		ofile<<altogether[i].name<<endl;
		ofile<<"���ο��Գɼ���"<<'\t'<<altogether[i].mark.pol<<endl;
        ofile<<"���Ŀ��Գɼ���"<<'\t'<<altogether[i].mark.chn<<endl;
        ofile<<"Ӣ�￼�Գɼ���"<<'\t'<<altogether[i].mark.eng<<endl;
        ofile<<"��������Գɼ���"<<'\t'<<altogether[i].mark.com<<endl;
        ofile<<"���Գɼ���"<<'\t'<<altogether[i].mark.oral<<endl;
        ofile<<"����֣�"<<'\t'<<altogether[i].Sage<<endl;
        ofile<<"ѧ����"<<'\t'<<altogether[i].Srecord<<endl;
        ofile<<"����������"<<'\t'<<altogether[i].Swlen<<endl;
	}
	ofile.close();
	ofile.open("d:\\¼ȡ֪ͨ��1.txt");
	ofile<<"¼ȡ֪ͨ��"<<endl;
	ofile<<altogether[0].name<<"��¼ȡ"<<endl;
	ofile.close();
	ofile.open("d:\\¼ȡ֪ͨ��2.txt");
	ofile<<"¼ȡ֪ͨ��"<<endl;
	ofile<<altogether[1].name<<"��¼ȡ"<<endl;
	ofile.close();
	ofile.open("d:\\¼ȡ֪ͨ��3.txt");
	ofile<<"¼ȡ֪ͨ��"<<endl;
	ofile<<altogether[2].name<<"��¼ȡ"<<endl;
	ofile.close();
	ofile.open("d:\\¼ȡ֪ͨ��4.txt");
	ofile<<"¼ȡ֪ͨ��"<<endl;
	ofile<<altogether[3].name<<"��¼ȡ"<<endl;
	ofile.close();
	ofile.open("d:\\¼ȡ֪ͨ��5.txt");
	ofile<<"¼ȡ֪ͨ��"<<endl;
	ofile<<altogether[4].name<<"��¼ȡ"<<endl;
	ofile.close();
	char name[20];
	cout<<"Ҫ��ѯ�ɼ��Ŀ�������Ϊ��"<<endl;
	cin>>name;
	for(i=0;i<num;i++){
		if(!strcmp(name,altogether[i].name)){
			cout<<altogether[i].name<<endl;
		    cout<<"���ο��Գɼ���"<<'\t'<<altogether[i].mark.pol<<endl;
            cout<<"���Ŀ��Գɼ���"<<'\t'<<altogether[i].mark.chn<<endl;
            cout<<"Ӣ�￼�Գɼ���"<<'\t'<<altogether[i].mark.eng<<endl;
            cout<<"��������Գɼ���"<<'\t'<<altogether[i].mark.com<<endl;
            cout<<"���Գɼ���"<<'\t'<<altogether[i].mark.oral<<endl;
            cout<<"����֣�"<<'\t'<<altogether[i].Sage<<endl;
            cout<<"ѧ����"<<'\t'<<altogether[i].Srecord<<endl;
            cout<<"����������"<<'\t'<<altogether[i].Swlen<<endl;
			break;
		}
	}
	return 0;
	}
