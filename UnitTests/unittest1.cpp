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
		TEST_METHOD(_YearsPassed)
		{
			ObjectOriented language;
			language.Year = 2014;
			int actual = YearsPassed(&language);
			int expected = 2020 - language.Year;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestCompareM)
		{
			Functional *language_new = new Functional;
			Procedural *language_old = new Procedural;
			language_new->mKey = type::FUNCTIONAL;
			language_new->Year = 2020;
			language_old->mKey = type::PROCEDURAL;
			language_old->Year = 2010;
			//<
			bool actual = Compare((Language*)language_new, (Language*)language_old);
			bool expected = true;
			Assert::AreEqual(expected, actual, L"Все плохо");
		}
		TEST_METHOD(ProceduralInputM)
		{
			ifstream fin("In_Proc_Test.txt");

			Procedural *actual = InProc(fin);
			Procedural *expected = new Procedural;

			expected->mAbstractDT = 0;
			expected->Year = 2000;
			expected->mKey = type::PROCEDURAL;
			expected->mRef = 20000;

			Assert::AreEqual(expected->mAbstractDT, actual->mAbstractDT);
			Assert::AreEqual(expected->Year,actual->Year);
			Assert::AreEqual((int)expected->mKey, (int)actual->mKey);
			Assert::AreEqual(expected->mRef, actual->mRef);
		}
		TEST_METHOD(ProceduralOutput)
		{
			ofstream fout("Out_Proc_Test_Act.txt");
			Procedural* act = new Procedural;
			act->mAbstractDT = 0;
			act->Year = 2020;
			act->mKey = type::PROCEDURAL;
			act->mRef = 20000;

			Out(act, fout);
			ifstream fin_act("Out_Proc_Test_Act.txt");
			ifstream fin_exp("Out_Proc_Test_Exp.txt");
			string expected, actual;
			getline(fin_exp, expected, '\0');
			getline(fin_act, actual, '\0');
			Assert::AreEqual(expected, actual, L"Не совпадает строка");
		}
		TEST_METHOD(ContainerStream)
		{
			ifstream fin("ContainerOutputIn.txt");
			ofstream fout("ContainerOutput.txt");
			Container c;
			Init(c);
			In(c, fin);
			Out(c, fout);
			fout.close();
			ifstream fin_exp("SortContainerExp.txt");
			ifstream fin_act("ContainerOutput.txt");
			string expected((std::istreambuf_iterator<char>(fin_exp)),std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(SortContainer)
		{
			ifstream fin("ContainerOutputIn.txt");
			ofstream fout("ContainerOutput.txt");
			Container *c = new Container;
			Init(*c);
			In(*c, fin);
			Sort(c);
			Out(*c, fout);
			fout.close();
			ifstream fin_exp("SortContainerExp.txt");
			ifstream fin_act("ContainerOutput.txt");
			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());
			Assert::AreEqual(expected, actual);
		}
	};
}