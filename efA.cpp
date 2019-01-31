/*
 * efA.cpp
 *
 *  Created on: 25/04/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Menu.h"

using namespace std;

int main()
{
	srand(time(NULL));
	cout << "              HomeStudies";
	Menu m;
	int opcao = -1;
	int subOpcao = -1;
	do
	{
		m.lerOpcao();
		opcao = m.getOpcao();
		if (opcao == 1)
		{
			do
			{
				m.lerSubOpcao(1);
				subOpcao = m.getSubOpcao();
				if (subOpcao == 1)
					m.adicionarQuestao();
				if (subOpcao == 2)
					m.removerQuestao();
				if (subOpcao == 3)
					m.listarQuestoes();
				if (subOpcao == 4)
					m.listarQuestoesDisc();
				if (subOpcao == 5)
					m.listarQuestoesMat();
				if (subOpcao < 1 || subOpcao > 6)
					cout << "Erro na opcao (valores possiveis: 1 - 6)" << endl;
			} while (m.getSubOpcao() != 6);
		}
		if (opcao == 2)
		{
			do
			{
				m.lerSubOpcao(2);
				subOpcao = m.getSubOpcao();
				if (subOpcao == 1)
					m.gerarTesteDisc();
				if (subOpcao == 2)
					m.gerarTesteMat();
				if (subOpcao == 3)
					m.removerTeste();
				if (subOpcao == 4)
					m.listarTestes();
				if (subOpcao == 5)
					m.listarTestesDisc();
				if (subOpcao == 6)
					m.analisarTeste();
				if (subOpcao == 7)
					m.resolverTeste();
				if (subOpcao == 8)
					m.exportarTeste();
				if (subOpcao < 1 || subOpcao > 9)
					cout << "Erro na opcao (valores possiveis: 1 - 9)" << endl;
			} while (m.getSubOpcao() != 9);
		}
		if (opcao < 1 || opcao > 3)
			cout << "Erro na opcao (valores possiveis: 1 - 3)" << endl;
	} while (m.getOpcao() != 3);
	cout << "--------------------------------------" << endl;
	cout << "              HomeStudies" << endl;
	return 0;
}

