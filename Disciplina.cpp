/*
 * Disciplina.cpp
 *
 *  Created on: 25/04/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "Disciplina.h"

//construtor elementar e sem parâmetros
Disciplina::Disciplina(string n) :
		nome(n)
{
}

//construtor por cópia
Disciplina::Disciplina(const Disciplina &d) :
		nome(d.nome)
{
}

//destrutor
Disciplina::~Disciplina()
{
}

//retorna o nome da disciplina
string Disciplina::getNome() const
{
	return nome;
}

//modifica o nome da disciplina
void Disciplina::setNome(string n)
{
	nome = n;
}

//retorna true se a disciplina indicada é igual à discipina objeto
bool Disciplina::operator==(const Disciplina &d) const
{
	return (bool) !nome.compare(d.nome);
}

