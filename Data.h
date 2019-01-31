/*
 * Data.h
 *
 *  Created on: 30/04/2015
 *      Author: José Félix Póvoa
 */

#ifndef DATA_H_
#define DATA_H_

class Data
{
private:
	int dia;
	int mes;
	int ano;
public:
	Data();
	Data(int, int, int);
	Data(const Data &);
	virtual ~Data();

	int getDia() const;
	int getMes() const;
	int getAno() const;
};

#endif /* DATA_H_ */
