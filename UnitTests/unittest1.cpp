#include "stdafx.h"
#include "CppUnitTest.h"
#include "../programming language/Container.h"
#include "../programming language/Functional.h"
#include "../programming language/Language.h"
#include "../programming language/ObjectOriented.h"
#include "../programming language/Procedural.h"

#include "../programming language/Container_Constr.cpp"
#include "../programming language/Container_In.cpp"
#include "../programming language/Container_Out.cpp"
#include "../programming language/Functional_In.cpp"
#include "../programming language/Functional_Out.cpp"
#include "../programming language/Language_Compare.cpp"
#include "../programming language/Language_In.cpp"
#include "../programming language/Language_Out.cpp"
#include "../programming language/ObjectOriented_In.cpp"
#include "../programming language/ObjectOriented_Out.cpp"
#include "../programming language/Procedural_In.cpp"
#include "../programming language/Procedural_Out.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(ProceduralInputM) //проверка только вводимых данных. взяли процедурный
		{
			ifstream fin("In_Proc_Test.txt"); //значения лежат в самом файле

			Procedural* actual = InProc(fin);
			Procedural* expected = new Procedural;

			// 1 0 2000 20000
			expected->mKey = type::PROCEDURAL;
			expected->mAbstractDT = 0;
			expected->Year = 2000;
			expected->mRef = 20000;

			Assert::AreEqual(expected->mAbstractDT, actual->mAbstractDT, L"Не совпадает");
			Assert::AreEqual(expected->Year, actual->Year, L"Не совпадает");
			Assert::AreEqual((int)expected->mKey, (int)actual->mKey, L"Не совпадает");
			Assert::AreEqual(expected->mRef, actual->mRef, L"Не совпадает");
		}
		TEST_METHOD(ProceduralOutput)
		{
			ofstream fout("Out_Proc_Test_Act.txt"); //файл, куда запишем данные: 1 0 2020 20000
			//ofstream f("Out_Proc_Test_Exp.txt");
			Procedural* act = new Procedural;

			act->mKey = type::PROCEDURAL;
			act->mAbstractDT = 0;
			act->Year = 2020;
			act->mRef = 20000;

			Out(act, fout);//запишем данные
			//Out(act, f);

			ifstream fin_act("Out_Proc_Test_Act.txt");
			ifstream fin_exp("Out_Proc_Test_Exp.txt"); //проверяем на совпадение. при любом изменении выводимого файла произойдет ошибка

			string expected, actual;

			getline(fin_exp, expected, '\0');
			getline(fin_act, actual, '\0');

			Assert::AreEqual(expected, actual, L"Не совпадает");
		}
		TEST_METHOD(ContainerStream) //проверка реализации контейнера
		{
			ifstream fin("ContainerOutputIn.txt");
			ofstream fout("ContainerOutput.txt");
			//ofstream f("ContainerOutputExp.txt");

			Container c;
			Init(c);
			In(c, fin);

			Out(c, fout);
			//Out(c, f);

			fout.close();

			ifstream fin_exp("ContainerOutputExp.txt");
			ifstream fin_act("ContainerOutput.txt");

			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());

			Assert::AreEqual(expected, actual, L"Не совпадает");
		}
		TEST_METHOD(SortContainer) //проверка на сортированный контейнер
		{
			ifstream fin("ContainerOutputIn.txt");
			ofstream fout("SortContainerOutput.txt");

			//ofstream f("SortContainerExp.txt");
			
			Container* c = new Container;

			Init(*c);
			In(*c, fin);
			Sort(c);

			Out(*c, fout);
			//Out(*c, f);

			fout.close();

			ifstream fin_exp("SortContainerExp.txt");
			ifstream fin_act("SortContainerOutput.txt");

			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());

			Assert::AreEqual(expected, actual, L"Не совпадает");
		}
		TEST_METHOD(OnlyProc) //проверка на вывод только процедуры
		{
			ifstream fin("ContainerOutputIn.txt");
			ofstream fout("OnlyProcOutput.txt");
			//ofstream f("OnlyProcOutputrExp.txt");
			
			Container* c = new Container;
			
			Init(*c);
			In(*c, fin);

			ProcOut(*c, fout);
			//ProcOut(*c, f);

			fout.close();

			ifstream fin_exp("OnlyProcOutputrExp.txt");
			ifstream fin_act("OnlyProcOutput.txt");

			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());

			Assert::AreEqual(expected, actual, L"Не совпадает");
		}
	};
}