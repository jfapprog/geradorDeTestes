/*
 * Data.cpp
 *
 *  Created on: 30/04/2015
 *      Author: José Félix Póvoa
 */

#include "Data.h"

Data::Data() :
 dia(1), mes(1), ano(2015)
{
}

Data::Data(int d, int m, int a) :
		dia(d), mes(m), ano(a)
{
}

Data::Data(const Data &d) :
		dia(d.dia), mes(d.mes), ano(d.ano)
{
}

Data::~Data()
{
}

int Data::getDia() const
{
	return dia;
}

int Data::getMes() const
{
	return mes;
}

int Data::getAno() const
{
	return ano;
}


