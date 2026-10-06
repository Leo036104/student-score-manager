#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Student {
	string id;
	string name;
	vector<double> cj;
	double suanshu() const {
		double sum = 0;
		for (double x : cj) sum += x;
		return sum;
	}
	double average() const {
		if (cj.empty()) return 0.0;
		return suanshu() / cj.size();
	}
};
vector<Student> students;
void addStudents() {
	string xuehao, xingming;
	double s1, s2, s3;
	Student m;
	cout << "请输入：学号 姓名 成绩1 成绩2 成绩3" << endl;
	cin >> xuehao >> xingming >> s1 >> s2 >> s3;//输入
	m.id = xuehao;
	m.name = xingming;
	m.cj.push_back(s1); m.cj.push_back(s2); m.cj.push_back(s3);//存入成绩
	students.push_back(m);
	cout << "添加成功!当前共" << students.size() << "名学生" << endl;
}
void showAll(const vector<Student>& xuesheng) {
	if (xuesheng.empty()) {
		cout << "暂无学生数据" << endl;
		return;
	}
	cout << "学号\t姓名\t成绩1\t成绩2\t成绩3\t总分\t平均分" << endl;
	for (int i = 0; i < xuesheng.size(); ++i) {
		cout << xuesheng[i].id << "\t" << xuesheng[i].name << "\t";
		for (int j = 0; j < xuesheng[i].cj.size(); ++j) {
			cout << xuesheng[i].cj[j] << "\t";
		}
		cout << xuesheng[i].suanshu() << "\t" << xuesheng[i].average() << endl;
	}
}
void findStu(const vector<Student>& xuesheng) {
	string target;
	cout << "请输入要查找的学号：";
	cin >> target;
	for (int i = 0; i < xuesheng.size(); ++i) {
		if (target == xuesheng[i].id) {
			cout << "找到了！" << endl;
			cout << xuesheng[i].id << "\t" << xuesheng[i].name << "\t";
			for (int j = 0; j < xuesheng[i].cj.size(); ++j)
				cout << xuesheng[i].cj[j] << "\t";
			cout << xuesheng[i].suanshu() << "\t" << xuesheng[i].average() << endl;
			return;
		}
	}
	cout << "未找到学号为 " << target << " 的学生" << endl;
}
int main(){
	int k;
	while (true) {
		cout << "===== 学生管理系统 =====" << endl;
		cout << "1.添加学生" << endl;
		cout << "2.显示所有学生" << endl;
		cout << "3.按学号查找" << endl;
		cout << "0.退出" << endl;
		cout << "请选择：";
		cin >> k;
		switch (k) {
		case 1 :
			addStudents(); 
			break;
		case 2 :
			showAll(students);
			break;
		case 3: 
			findStu(students);
			break;
		case 0: cout << "你退出了系统" << endl; break;
		default: cout << "无效选项" << endl; break;
		}
		if (k == 0)
			break;

	}
	return 0;
}