/*
 * Questao.cpp
 *
 *  Created on: 26/04/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "Questao.h"

//construtor sem parâmetros
Questao::Questao() :
		bimestre(0), materia(), enunciado(""), gabarito("")
{
}

//construtor elementar
Questao::Questao(int b, const Materia &m, string e, string g) :
		bimestre(b), materia(m), enunciado(e), gabarito(g)
{
}

//construtor por cópia
Questao::Questao(const Questao &q) :
		bimestre(q.bimestre), materia(q.materia), enunciado(q.enunciado), gabarito(
				q.gabarito)
{
}

//destrutor
Questao::~Questao()
{
}

//retorna o bimestre
int Questao::getBimestre() const
{
	return bimestre;
}

//retorna uma referência constante para a matéria
const Materia & Questao::getMateria() const
{
	return materia;
}

//retorna o enunciado
string Questao::getEnunciado() const
{
	return enunciado;
}

//retorna o gabarito
string Questao::getGabarito() const
{
	return gabarito;
}

//modifica o semestre
void Questao::setBimestre(int b)
{
	bimestre = b;
}

//modifica a matéria
void Questao::setMateria(const Materia &m)
{
	materia = m;
	//a afetação ocorre sem problemas porque Materia não tem atributos ponteiros
}

//modifica o enunciado
void Questao::setEnunciado(string e)
{
	enunciado = e;
}

//modifica o gabarito
void Questao::setGabarito(string g)
{
	gabarito = g;
}

//escreve os atributos da questão
void Questao::escrever() const
{
	materia.escrever();
	cout << "Bimestre: " << bimestre << endl;
	cout << "Enunciado: " << enunciado << endl;
	cout << "Gabarito: " << gabarito << endl;
}
