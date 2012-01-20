#include "GameClass.h"

Game::Game(){}

Person * Game::get_population()
{
	return pop;
}

Person Game::get_person(int x)
{
	return pop[x];
}

CmdNode * Game::cmd_move(Person p, int x, int y)
{ 
	CmdList * cmdList = new CmdList();
	
	cmdList->addCmd(0);
	cmdList->addCmd(1);
	cmdList->addCmd(2);
	cmdList->addCmd(3);
	cmdList->addCmd(4);
	cmdList->addCmd(5);
	cmdList->addCmd(6);
	cmdList->addCmd(7);
	cmdList->addCmd(8);
	cmdList->addCmd(9);
	

	return cmdList->CmdList::getHead();		
}
Squad Game::get_squad(int x){
	return squad[x];
}
Player Game::get_player(int x){
	return player[x];
}
int Game::get_board_value(int x, int y)
{
	return board[x][y];
}
int Game::Start(void * arg){
   Arg(arg); // store user data
   //int code = thread_create(Game::EntryPoint, this, & ThreadId_);
   return 1;
}


int Game::get_time()
{
	return moveNum;
}



void Game::Setup(int mapSelection){
	cout <<"Game Setup Commencing\n";
	int gamePop = 8;
	int moveNum = 0;
	Player p0,p1;
	Squad s1, s0;
	
	MapPack maps;
	maps.MapPack::MapPack();
	maps.MapPack::load_map(mapSelection);
	cout <<"Sending Print Map Command \n";
	maps.MapPack::print_map();
	/*
	int *tmp = maps.get_map();
    int **me = &(tmp);
	board = me;
	*/
	for (int i = 0; i < 32; i++){
		for (int j = 0; j <48; j++){
			board[i][j] = maps.MapPack::get_map_value(i,j);
		}
	}


	cout <<"Initializing Board\n";
	
	/*
    int ** board = new int*[rows];
    for(int i = 0; i < rows; i++)
    board[i] = new int[columns];

	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 48; j++){
			(*board)[i][j] = 0;
		}
	}
	*/

	cout <<"Initializing Population\n";
	
	Person r0,r1,r2,r3,b0,b1,b2,b3;
	
	//Initialize Positions
	//Starting positions 32x48
	r0.set_boardPosition(16,24);
	r1.set_boardPosition(5,4);
	r2.set_boardPosition(6,4);
	r3.set_boardPosition(7,4);
	b0.set_boardPosition(17,42);
	b1.set_boardPosition(16,42);
	b2.set_boardPosition(15,42);
	b3.set_boardPosition(14,42);
	cout <<"Board Positions Set \n";

	//Put in Squads
	r0.set_squadNum(1);
	r1.set_squadNum(1);
	r2.set_squadNum(1);
	r3.set_squadNum(1);
	b0.set_squadNum(2);
	b1.set_squadNum(2);
	b2.set_squadNum(2);
	b3.set_squadNum(2);
	cout <<"Persons' SquadNum Set To Squads \n";
	//Make proper population intializer
	//for (int i = 0; i < SIZE; i++)
	
	pop0[0] = r0;
	pop0[1] = r1;
	pop0[2] = r2;
	pop0[3] = r3;
	pop1[0] = b0;
	pop1[1] = b1;
	pop1[2] = b2;
	pop1[3] = b3;
	pop[0] = r0;
	pop[1] = r1;
	pop[2] = r2;
	pop[3] = r3;
	pop[4] = b0;
	pop[5] = b1;
	pop[6] = b2;
	pop[7] = b3;
	cout <<"Persons Grouped For Squad Assignment\n";

	s0.Squad::load_units(pop0,SIZE);
	cout <<"Squad 0: Units Assigned\n";

	s1.Squad::load_units(pop1,SIZE);
	cout <<"Squad 1: Units Assigned\n";

	p0.Player::load_squad(s0);
	cout <<"Player 0: Squad Assigned\n";

	p1.Player::load_squad(s1);
	cout <<"Player 1: Squad Assigned\n";

	set_squad(s0, 0);
	cout <<"Game   : Squad 0 Loaded\n";

	set_squad(s1, 1);
	cout <<"Game   : Squad 1 Loaded\n";

	int count = 0;
	for (int i = 0; i < 8; i++){ 
		cout << "Spawning Person " << pop[i].cmdIdentify() << " at Location " << pop[i].Person::boardRowValue << " " << pop[i].Person::boardColumnValue << " \n";
		spawn_unit(pop[i]); // rights to board
		count++;
	}
	if (count != 8){
		cout << "Some units were not spawned\n";
	}
}

void Game::EntryPoint(void * pthis){
	int * mapSelection;
	mapSelection = (int *)pthis;
	Game * pt = (Game*)pthis;
	int temp = *mapSelection;

	pt->Setup( temp);
}


void Game::Execute(void* arg){}
void Game::move_unit(CmdNode * cmdListHead, Person p, int time)
{
	//int time = t.Time::get_time();
	int loopCount = 0;
	cout << "Made it into move_unit method\n";
	CmdNode * temp = cmdListHead;
	cout << "Stored Head of cmdList in temporary memory\n";
	if (temp->next == NULL || temp->cmd < 0){cout << "CmdList arrived Null\n";}
	cout << "Entering while decoding loop\n";

	while (temp->next != NULL)
	{		
		
		cout << "Decode loop " << loopCount << " \n";
		cout << "Move Cmd " << temp->cmd << " \n";
		if (temp->cmd == -1)
		{

			string IdentityOfPerson;
			IdentityOfPerson = p.cmdIdentify(); //string to identify who is done moving
			cout << IdentityOfPerson << " has arrived at his/her destination\n";
			
			
		}
		if (temp->cmd == 0)
		{
			wait(1);temp = temp->next;
		}
		if (temp->cmd == 1)
		{
			p.Person::set_boardPosition(p.get_boardRowValue()+1,p.get_boardColumnValue());
			wait(1); 
			temp = temp->next;
			set_board_value(p.get_boardRowValue(),p.get_boardColumnValue(), 0);
			set_board_value(p.get_boardRowValue()+1,p.get_boardColumnValue(),p.Person::get_squadNum()); 
		}
		if (temp->cmd == 2)
		{
			p.Person::set_boardPosition(p.get_boardRowValue()+1,p.get_boardColumnValue()+1);
			wait(1); 
			temp = temp->next;
			set_board_value(p.get_boardRowValue(),p.get_boardColumnValue(), 0);
			set_board_value(p.get_boardRowValue()+1,p.get_boardColumnValue()+1,p.Person::get_squadNum()); 
		}
		if (temp->cmd == 3)
		{
			p.Person::set_boardPosition(p.get_boardRowValue()  ,p.get_boardColumnValue()+1);
			wait(1); 
			temp = temp->next;}
			set_board_value(p.get_boardRowValue(),p.get_boardColumnValue(), 0);
			set_board_value(p.get_boardRowValue(),p.get_boardColumnValue()+1,p.Person::get_squadNum()); 
		if (temp->cmd == 4)
		{
			p.Person::set_boardPosition(p.get_boardRowValue()-1,p.get_boardColumnValue()+1);
			wait(1); 
			temp = temp->next;
			set_board_value(p.get_boardRowValue(),p.get_boardColumnValue(), 0);
			set_board_value(p.get_boardRowValue()-1,p.get_boardColumnValue()+1,p.Person::get_squadNum()); 
		}
		if (temp->cmd == 5)
		{
			p.Person::set_boardPosition(p.get_boardRowValue()-1,p.get_boardColumnValue());
			wait(1); 
			temp = temp->next;
			set_board_value(p.get_boardRowValue(),p.get_boardColumnValue(), 0);
			set_board_value(p.get_boardRowValue()-1,p.get_boardColumnValue(),p.Person::get_squadNum()); 
		}
		if (temp->cmd == 6)
		{
			p.Person::set_boardPosition(p.get_boardRowValue()-1,p.get_boardColumnValue()-1);
			wait(1); 
			temp = temp->next;
			set_board_value(p.get_boardRowValue(),p.get_boardColumnValue(), 0);
			set_board_value(p.get_boardRowValue()-1,p.get_boardColumnValue()-1,p.Person::get_squadNum()); 
		}
		if (temp->cmd == 7)
		{
			p.Person::set_boardPosition(p.get_boardRowValue()  ,p.get_boardColumnValue()-1);
			wait(1); 
			temp = temp->next;
			set_board_value(p.get_boardRowValue(),p.get_boardColumnValue(), 0);
			set_board_value(p.get_boardRowValue(),p.get_boardColumnValue()-1,p.Person::get_squadNum()); 
		}
		if (temp->cmd == 8)
		{
			p.Person::set_boardPosition(p.get_boardRowValue()+1,p.get_boardColumnValue()-1);
			wait(1); 
			temp = temp->next;
			set_board_value(p.get_boardRowValue(),p.get_boardColumnValue(), 0);
			set_board_value(p.get_boardRowValue()+1,p.get_boardColumnValue()-1,p.Person::get_squadNum()); 

		}
	}
}
void Game::load_player(Player p, int x)
{
	player[x] = p;
}
void Game::load_population(Person * p, int pop)
{
	int toBePopulated = pop;
	for (int i = 0; i < pop; i++)
	{ 
		cout << "Spawning Person " << p[i].cmdIdentify() << " at Location " << p[i].Person::boardRowValue << " " << p[i].Person::boardColumnValue << " \n";
		spawn_unit(p[i]);
		toBePopulated--;
	}
	if (toBePopulated > 0)
	{
		cout << "Some units were not spawned\n";
	}

}

void Game::init_pop()
{
	
}

void Game::new_tile()
{
	for (int i = 0; i < 255; i++) 
	{
		for (int j = 0; j < 255; j++) 
		{
			this->tile[i][j] = 0;
		}
	}
}

void Game::spawn_unit(Person p)
{
	//int temp = p->Person::get_squadNum();
	board[p.Person::get_boardRowValue()][p.Person::get_boardColumnValue()] = p.Person::get_squadNum();
	//tile[p.Person::get_boardRowValue()][p.Person::get_boardColumnValue()] = p.Person::get_squadNum();
}

void Game::set_tile(int x, int y, int z){
	//0 =   = free
	//1 = X = person
	//2 = W = wall
	//3 = L = ledge
	//e = E = error
	tile[x][y] = z;
}


void Game::set_board_value(int x, int y, int z)
{
	board[x][y] = z;
}
void Game::set_squad(Squad sqd, int x){
	squad[x] = sqd;
}
bool Game::is_free(int x, int y)
{
	if (board[x][y] == 0)
	{
		return true;
	}
	else
		return false;
}




/* If game working when you find this, delete this code
void Game::load_board(int boaNum)
{

		//0 =   = free
		//1 = X = person
		//2 = W = wall
		//3 = L = ledge
		//e = E = error

	int mapBigTest[32][48] = 
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,3,3,3,3,3,3,3,3,3,3,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,3,4,4,4,3,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,3,0,0,0,0,0,0,3,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,3,0,0,0,0,0,0,3,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,3,3,3,3,3,0,0,3,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0},
		{0,0,0,0,3,3,3,3,3,0,3,3,3,0,3,3,3,0,3,3,3,3,3,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0},
		{0,0,0,0,0,0,3,0,0,0,3,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,3,0,0,0,3,3,3,0,3,3,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,3,0,0,0,3,0,0,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,3,0,0,0,3,3,3,0,3,3,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	int mapCrossHair[16][16] =
	{
		{0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0},
		{0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0},
		{0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0},
		{0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0},
		{0,0,0,0,0,2,3,0,0,3,2,0,0,0,0,0},
		{2,2,2,2,2,3,3,0,0,3,3,2,2,2,2,2},
		{2,2,2,2,3,3,3,0,0,3,3,3,2,2,2,2},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{2,2,2,2,3,3,3,0,0,3,3,3,2,2,2,2},
		{2,2,2,2,2,3,3,0,0,3,3,2,2,2,2,2},
		{0,0,0,0,0,2,3,0,0,3,2,0,0,0,0,0},
		{0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0},
		{0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0},
		{0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0},
		{0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0}
	};

	int mapZeroPlane[16][16] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

		int mapSeigeHouse[16][16] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,2,2,3,3,2,3,3,2,2,0,0,0,0,0},
		{0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0},
		{0,0,3,0,0,0,2,0,2,3,2,0,0,0,0,0},
		{0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,0},
		{0,0,2,0,0,0,3,0,0,0,0,0,0,3,0,0},
		{0,0,2,3,3,2,2,0,0,0,0,0,3,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,3,0,3,0,0,0,0,0},
		{0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,0},
		{0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	if (boaNum == 3)
	{
	
		for (int i = 0; i < 32; i++) 
		{
			for (int j = 0; j < 48; j++) 
			{
				board[i][j] = mapBigTest[i][j];
			}
		}
	}
	if (boaNum == 2)
	{
	
		for (int i = 0; i < 16; i++) 
		{
			for (int j = 0; j < 16; j++) 
			{
				board[i][j] = mapSeigeHouse[i][j];
			}
		}
	}

	if (boaNum == 1)
	{
	
		for (int i = 0; i < 16; i++) 
		{
			for (int j = 0; j < 16; j++) 
			{
				board[i][j] = mapCrossHair[i][j];
			}
		}
	}

	if (boaNum == 0)
	{
	
		for (int i = 0; i < 16; i++) 
		{
			for (int j = 0; j < 16; j++) 
			{
				board[i][j] = mapZeroPlane[i][j];
			}
		}
	}

}
*/