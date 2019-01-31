/*
 * Menu.h
 *
 *  Created on: 27/04/2015
 *      Author: José Félix Póvoa
 */

#ifndef MENU_H_
#define MENU_H_

#include "ListaQuestoes.h"
#include "ListaTestes.h"

class Menu
{
private:
	ListaQuestoes questoes;
	ListaTestes testes;
	int opcao;
	int subOpcao;

	void inicializar();
public:
	Menu();
	virtual ~Menu();

	int getOpcao() const;
	int getSubOpcao() const;

	void lerOpcao();
	void lerSubOpcao(int);

	void adicionarQuestao();
	void removerQuestao();
	void listarQuestoes() const;
	void listarQuestoesDisc() const;
	void listarQuestoesMat() const;

	void gerarTesteDisc();
	void gerarTesteMat();
	void removerTeste();
	void listarTestes() const;
	void listarTestesDisc() const;
	void analisarTeste() const;
	void resolverTeste() const;
	void exportarTeste() const;
};

#endif /* MENU_H_ */
