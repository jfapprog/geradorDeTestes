/*
 * Materia.cpp
 *
 *  Created on: 25/04/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "Materia.h"

//construtor sem parâmetros
Materia::Materia() :
		nome(""), serie(0), disciplina()
{
}

//construtor elementar
Materia::Materia(string n, int s, const Disciplina &d) :
		nome(n), serie(s), disciplina(d)
{
}

//construtor por cópia
Materia::Materia(const Materia &m) :
		nome(m.nome), serie(m.serie), disciplina(m.disciplina)
{
}

//destrutor
Materia::~Materia()
{
}

//retorna o nome
string Materia::getNome() const
{
	return nome;
}

//retorna a série
int Materia::getSerie() const
{
	return serie;
}

//retorna uma referência constante para a disciplina
const Disciplina & Materia::getDisciplina() const
{
	return disciplina;
}

//modifica o nome
void Materia::setNome(string n)
{
	nome = n;
}

//modifica a série
void Materia::setSerie(int s)
{
	serie = s;
}

//modifica a disciplina
void Materia::setDisciplina(const Disciplina &d)
{
	disciplina = d;
	//a afetação ocorre sem problemas porque Disciplina não tem atributos ponteiros
}

//retorna true se a matédia indicada é igual à matéria objeto
bool Materia::operator ==(const Materia &m) const
{
	if (!nome.compare(m.nome) && serie == m.serie && disciplina == m.disciplina)
		return true;
	return false;
}

//escreve os atributos da matéria
void Materia::escrever() const
{
	cout << "Disciplina: " << disciplina.getNome() << endl;
	cout << "Materia: " << nome << endl;
	cout << "Serie " << serie << endl;
}

