//#include<string>
//#include<iostream>
//#include<fstream>
//#include<algorithm>
//#include<vector>
//#include<map>
//using namespace std;
//
//
//struct a_word {
//	char ch;
//	int count;
//	a_word() { count = 0; };
//};
//a_word first[26];//ͳ����ĸ�����Ľṹ������
//long long number = 0;//��ٷ��ĸ���ͳ��
//string password_str = "";//����
//int ans = 0;//ͳ���м�¼����ĸ����
//map<char, int> m;//���ݷ��ķ�������
//map<char, char> key_mi;//��Կ
//
//bool cmp(a_word a, a_word b)
//{
//	return (a.count > b.count);
//}
////��Сдת��
//string conform(string str)
//{
//	string s = "";
//	for (int i = 0; i < str.length(); i++)
//	{
//		if (str[i] >= 'A' && str[i] <= 'Z')
//		{
//			s += (char)str[i] + ('a' - 'A');
//		}
//
//	}
//	return s;
//
//}
////�ַ����滻����
//void replace_str(string & str, char a, char b)
//{
//	for (int i = 0; i < str.length(); i++)
//	{
//		if (str[i]== a)
//		{
//			str[i] = b;
//		}
//	}
//}
////��Կ�����Ķ�Ӧ
//string solve(string password)
//{
//	string line_str="";
//	string mingwen = password;
//	ifstream in("d:\\����ѧ�ļ�\\keyword.txt");
//	while (getline(in, line_str))
//	{
//		key_mi[line_str[0]+'a'-'A'] = line_str[3]-'A'+'a';
//	}
//	in.close();
//	char tmp = '$';
//	int count = 0;
//	bool vis[26] = { 0 };
//	for (char i='a'; i <='z'; i++)
//	{
//		if (key_mi[i] != i && vis[i-'a']==false && vis[key_mi[i]-'a']==false)
//		{
//			
//			replace_str(mingwen, i, tmp);
//			replace_str(mingwen, key_mi[i], i);
//			replace_str(mingwen, tmp, key_mi[i]);
//			vis[i - 'a'] = true;
//			vis[key_mi[i] - 'a'] = true;
//			count++;
//		}
//	}
//
//	return mingwen;
//}
////�������ַ�����������
//int include_num(string str ,string sub)
//{
//	int len = sub.length();
//	int count = 0;
//	while (str.length() >= len && str.find(sub)>=0)
//	{
//		int pos = str.find(sub);
//		str = str.substr(pos+len, str.length() - pos);
//		count++;
//	}
//	return count;
//	
//}
////����ʵ��ȫ����
//void DFS(string result,int count)
//{
//	if (count == 26)
//	{
//		cout << result << endl;
//		for (int i = 0; i < result.length(); i++)
//		{
//			key_mi['a' + i] = result[i];
//		}
//		string see_wen = solve(password_str);
//		if (include_num(see_wen, "the") == 12 && include_num(see_wen, "and") == 10)
//		{
//			number++;
//			cout << number << ":===>" << see_wen << endl;
//		}
//		key_mi.clear();
//	}
//	for (char c = 'a'; c <= 'z'; c++)
//	{
//		if (m[c] == 0)
//		{
//			string s = result + c;
//			m[c] = 1;
//			DFS(s, count + 1);
//			m[c] = 0;
//		}
//	}
//
//}
////��ٷ�
//void Exhaustion(string password_str)
//{
//	string result = "";
//	DFS(result, 0);
//}
////ͳ��Ƶ��
//void count_hz(a_word a[], string s)
//{
//	
//	for (int i = 0; i < s.length(); i++)
//	{
//		first[s[i]-'a'].count++;
//		first[s[i] - 'a'].ch = s[i];
//	}
//	sort(first, first+26, cmp);
//	cout << "��ĸ  " << "  ����" << "    Ƶ��" << endl;
//	for (int i = 0; i < 26; i++)
//	{
//		if (first[i].count != 0)
//		{
//			cout << first[i].ch << "\t" << first[i].count<<"\t"<< first[i].count*1.0/s.length() << endl;
//			ans++;
//		}
//	}
//
//	cout << "�м�¼�Ľ����ĸ��" << ans << " ��" << endl;
//
//}
////��ʾ��Կ
//void print_key()
//{
//	string s = "";
//	cout << "\t\tԭ��ĸ\t��Ӧ��ĸ" << endl;
//	ifstream in("d:\\����ѧ�ļ�\\keyword.txt");
//	while (getline(in,s))
//	{
//		cout << "\t\t" << s[0] << "\t" << s[3] << endl;
//	}
//	in.close();
//
//}
//
//int main()
//{
//	ifstream in("d:\\����ѧ�ļ�\\key.txt");
//	char ch;
//	int choice;
//	while (in.get(ch))
//	{
//		password_str += ch;
//	}
//	in.close();
//	//��дת��Сд
//	password_str = conform(password_str);
//	cout << "\tС���������ƽ�" << endl;
//	cout << "1.��ٷ�\n2.Ƶ�ʷ�����\n3.�������˳�" << endl;
//	while (1) {
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			//��ٷ�
//			cout << "====================��ٷ�================" << endl;
//			cout << "�����ƽ⡣����������������������������" << endl; 
//			Exhaustion(password_str);
//			break;
//		case 2:
//			cout << "=================Ƶ��ͳ��===================" << endl;
//			//ͳ��Ƶ��
//			count_hz(first, password_str);
//			cout << endl;
//
//			//�ƽ���
//			cout << "=====================����=====================" << endl;
//			cout << password_str << endl;
//			cout << endl;
//			cout << "=======================����=====================" << endl;
//			cout << solve(password_str) << endl;
//			cout << endl;
//			cout << "======================��Կ��������================" << endl;
//			print_key();
//			cout << endl;
//			break;
//		default:
//			break;
//		}
//		if (choice != 1 || choice != 2)break;
//
//		
//	}
//	system("pause");
//	return 0;
//}