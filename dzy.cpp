#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main(){
    struct Tmark                         //考试成绩
	{      float pol;                    //政治
           float chn;                    //语文
           float eng;                    //英语
           float com;                    //计算机
           float oral;                   //口试
	};
    struct Tmarks                        //应聘者信息和考试成绩
	{       char name[20];               //姓名
            float Sage;                  //年龄分
            float Srecord;               //学历分
            float Swlen;                 //工作经历分
            Tmark mark;                  //考试成绩
            float total;                 //总分
	};
    struct Tinform                       //应聘者个人信息       
{       char name[20];               //姓名
        char sex;                    //性别
        float age; 	                 //年龄
		char schoolrecord;           //学历
        float worklen;               //任科级干部年限
        char wordsite[60];           //现工作单位
		Tmark mark;                  //考试成绩
};
    Tinform people[50];
	int i,j,num;
	cout<<"学历  硕士用m表示 博士用d表示 本科用u表示 其他用o表示"<<endl;
	cout<<"性别 男用m表示 女用f表示"<<endl;
	cout<<"应聘人数为："<<endl;
	cin>>num;
	ifstream ifile;
	ifile.open("d:\\应聘者个人信息.txt");
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
	ofile.open("d:\\成绩总表.txt");
	for(i=0;i<num;i++){
		ofile<<endl;
		ofile<<altogether[i].name<<endl;
		ofile<<"政治考试成绩："<<'\t'<<altogether[i].mark.pol<<endl;
        ofile<<"语文考试成绩："<<'\t'<<altogether[i].mark.chn<<endl;
        ofile<<"英语考试成绩："<<'\t'<<altogether[i].mark.eng<<endl;
        ofile<<"计算机考试成绩："<<'\t'<<altogether[i].mark.com<<endl;
        ofile<<"口试成绩："<<'\t'<<altogether[i].mark.oral<<endl;
        ofile<<"年龄分："<<'\t'<<altogether[i].Sage<<endl;
        ofile<<"学历分"<<'\t'<<altogether[i].Srecord<<endl;
        ofile<<"工作经历分"<<'\t'<<altogether[i].Swlen<<endl;
	}
	ofile.close();
	ofile.open("d:\\录取通知书1.txt");
	ofile<<"录取通知书"<<endl;
	ofile<<altogether[0].name<<"被录取"<<endl;
	ofile.close();
	ofile.open("d:\\录取通知书2.txt");
	ofile<<"录取通知书"<<endl;
	ofile<<altogether[1].name<<"被录取"<<endl;
	ofile.close();
	ofile.open("d:\\录取通知书3.txt");
	ofile<<"录取通知书"<<endl;
	ofile<<altogether[2].name<<"被录取"<<endl;
	ofile.close();
	ofile.open("d:\\录取通知书4.txt");
	ofile<<"录取通知书"<<endl;
	ofile<<altogether[3].name<<"被录取"<<endl;
	ofile.close();
	ofile.open("d:\\录取通知书5.txt");
	ofile<<"录取通知书"<<endl;
	ofile<<altogether[4].name<<"被录取"<<endl;
	ofile.close();
	char name[20];
	cout<<"要查询成绩的考生姓名为："<<endl;
	cin>>name;
	for(i=0;i<num;i++){
		if(!strcmp(name,altogether[i].name)){
			cout<<altogether[i].name<<endl;
		    cout<<"政治考试成绩："<<'\t'<<altogether[i].mark.pol<<endl;
            cout<<"语文考试成绩："<<'\t'<<altogether[i].mark.chn<<endl;
            cout<<"英语考试成绩："<<'\t'<<altogether[i].mark.eng<<endl;
            cout<<"计算机考试成绩："<<'\t'<<altogether[i].mark.com<<endl;
            cout<<"口试成绩："<<'\t'<<altogether[i].mark.oral<<endl;
            cout<<"年龄分："<<'\t'<<altogether[i].Sage<<endl;
            cout<<"学历分"<<'\t'<<altogether[i].Srecord<<endl;
            cout<<"工作经历分"<<'\t'<<altogether[i].Swlen<<endl;
			break;
		}
	}
	return 0;
	}
