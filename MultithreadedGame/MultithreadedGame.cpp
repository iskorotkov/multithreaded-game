#include <iostream>
#include "EnemyThreadPool.h"
#include "Direction.h"

int main()
{
	EnemyThreadPool pool;
	const Enemy enemy1(Direction::LeftToRight, 0, 100);
	pool.AddNewEnemy(enemy1);
}
