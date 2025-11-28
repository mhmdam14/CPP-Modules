#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        storage[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
	{
        if (other.storage[i])
            storage[i] = other.storage[i]->clone();
        else
            storage[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
	{
        for (int i = 0; i < 4; i++)
		{
            delete storage[i];
            if (other.storage[i])
                storage[i] = other.storage[i]->clone();
            else
                storage[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete storage[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
		return;
    for (int i = 0; i < 4; i++)
	{
        if (!storage[i])
		{
            storage[i] = m->clone();
			delete m;
            return;
        }
    }
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++) {
        if (storage[i] && storage[i]->getType() == type)
            return storage[i]->clone();
    }
    return NULL;
}
