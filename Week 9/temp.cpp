#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

const int LEFT = 1;
const int RIGHT = 2;
const int DOWN = 3;
const int UP = 4;
const int NUM_DIRECTIONS = 4;

const int AREA_DIMENSION = 5;
const int INIT_DOODLEBUG_COUNT = 1;
const int INIT_ANT_COUNT = 1;
const int ANT_BREED_TIME = 3;
const int DOODLEBUG_BREED_TIME = 8;
const int DOODLEBUG_STARVE_TIME = 3;
const char EMPTY_SPACE = '-';
const char ANT = 'o';
const char DOODLEBUG = 'X';

struct Coordinate
{
    int x = -1;
    int y = -1;
};

int generate_random_integer(int lower_bound, int upper_bound)
{
    upper_bound = upper_bound + 1; // the below has upper as exclusive, this changes to inclusive
    int num = (std::rand() % (upper_bound - lower_bound)) + lower_bound;

    return num;
}

bool isin(std::vector<int> vec, int target)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == target)
        {
            return true;
        }
    }
    
    return false;
}

void shift_coordinates(int direction, int &x, int &y)
{
    switch (direction)
    {
        case LEFT:
            x -= 1;
            break;
        case RIGHT:
            x += 1;
            break;
        case DOWN:
            y -= 1;
            break;
        case UP:
            y += 1;
            break;
    }
}

bool is_valid_coordinate(int x, int y)
{
    return !(x < 0 || y < 0 || x >= AREA_DIMENSION || y >= AREA_DIMENSION);
}

std::vector<int> get_shuffled_directions()
{
    std::vector<int> shuffled_vec;
    std::vector<int> existing_directions;

    int direction = generate_random_integer(1, NUM_DIRECTIONS);
    shuffled_vec.push_back(direction);
    existing_directions.push_back(direction);

    while (shuffled_vec.size() < NUM_DIRECTIONS)
    {
        int direction = generate_random_integer(1, NUM_DIRECTIONS);
        
        if (!isin(existing_directions, direction))
        {
            shuffled_vec.push_back(direction);
            existing_directions.push_back(direction);
        }
    }
    
    return shuffled_vec;
}

class Organism;
class Ant;
class Doodlebug;
class Area;

class Organism
{
    protected:
        int x;
        int y;
        int time_survived;
        int time_until_breed;

    public:
        Area *current_state;
        Organism(Area *current_state, int x, int y);
        virtual char repr() = 0;
        virtual void move();
        Coordinate get_empty_adjacent_cell(int x, int y);
        virtual void breed() {};
        virtual bool is_starving() { return false; };
        virtual ~Organism() {};
};

class Ant : public Organism
{
    public:
        Ant(Area *current_state, int x, int y);
        char repr() { return ANT; };
        void breed();
};

class Doodlebug : public Organism
{
    private:
        Coordinate locate_ant(int x, int y);
        int time_until_starve;

    public:
        Doodlebug(Area *current_state, int x, int y);
        char repr() { return DOODLEBUG; };
        void move();
        void breed();
        bool is_starving() { return time_until_starve == 0; };
};

class Area
{
    public:
        Area();
        Organism *garden[AREA_DIMENSION][AREA_DIMENSION];
        void populate_garden();
        void print_garden();
        int time_survived;
        bool is_empty(int x, int y);
        void advance_time_step();
        void iterate(char target, std::string action);
        int ant_count();
        int doodlebug_count();
};

/*--------------------------------- AREA FUNCTIONS ---------------------------------*/

Area::Area()
{
    // set the seed
    std::srand(std::time(0));
    time_survived = 0;
    for (int i = 0; i < AREA_DIMENSION; i++)
    {
        for (int j = 0; j < AREA_DIMENSION; j++)
        {
            Area::garden[i][j] = nullptr;
        }
    }
}

bool Area::is_empty(int x, int y)
{
    return (Area::garden[x][y] == nullptr);
}

void Area::populate_garden()
{
    int ant_count = 0;
    while (ant_count < INIT_ANT_COUNT)
    {
        int x = generate_random_integer(0, AREA_DIMENSION - 1);
        int y = generate_random_integer(0, AREA_DIMENSION - 1);

        if (Area::garden[x][y] == nullptr)
        {
            Area::garden[x][y] = new Ant(this, x, y);
            ant_count += 1;
        }
    }
    
    int doodle_count = 0;
    while (doodle_count < INIT_DOODLEBUG_COUNT)
    {
        int x = generate_random_integer(0, AREA_DIMENSION - 1);
        int y = generate_random_integer(0, AREA_DIMENSION - 1);

        if (Area::garden[x][y] == nullptr)
        {
            Area::garden[x][y] = new Doodlebug(this, x, y);
            doodle_count += 1;
        }
    }
}

void Area::print_garden()
{
    std::cout << " \t";
    for (int i = 0; i < AREA_DIMENSION; i++)
    {
        std::cout << i << ' ';
        if (i <= 9)
        {
           std::cout << ' ';
        }
    }
    std::cout << '\n' << '\n';
    
    for (int x = 0; x < AREA_DIMENSION; x++)
    {
        std::cout << x << "\t";
        for (int y = 0; y < AREA_DIMENSION; y++)
        {
            if (Area::garden[x][y] == nullptr)
            {
                std::cout << EMPTY_SPACE;
            }
            else
            {
                std::cout << (*Area::garden[x][y]).repr();
            }

            std::cout << "  ";
        }

        std::cout << '\n';
    }
}

void Area::iterate(char target, std::string action)
{
    for (int x = 0; x < AREA_DIMENSION; x++)
    {
        for (int y = 0; y < AREA_DIMENSION; y++)
        {
            if (Area::garden[x][y] == nullptr)
            {
                continue;
            }

            if ((*Area::garden[x][y]).repr() == target)
            {
                if (action == "move")
                {
                    (*Area::garden[x][y]).move();
                }
                else if (action == "breed")
                {
                    (*Area::garden[x][y]).breed();
                }
            }   
        }
    }
}

void Area::advance_time_step()
{
    // doodlebugs move before the ants do
    for (int x = 0; x < AREA_DIMENSION; x++)
    {
        for (int y = 0; y < AREA_DIMENSION; y++)
        {
            if (Area::garden[x][y] == nullptr)
            {
                continue;
            }

            if ((*Area::garden[x][y]).repr() == DOODLEBUG)
            {
                (*Area::garden[x][y]).move();
            }   
        }
    }

    for (int x = 0; x < AREA_DIMENSION; x++)
    {
        for (int y = 0; y < AREA_DIMENSION; y++)
        {
            if (Area::garden[x][y] == nullptr)
            {
                continue;
            }

            if ((*Area::garden[x][y]).repr() == ANT)
            {
                (*Area::garden[x][y]).move();
            }   
        }
    }

    for (int x = 0; x < AREA_DIMENSION; x++)
    {
        for (int y = 0; y < AREA_DIMENSION; y++)
        {
            if (Area::garden[x][y] == nullptr)
            {
                continue;
            }

            if ((*Area::garden[x][y]).repr() == DOODLEBUG)
            {
                (*Area::garden[x][y]).breed();
            }   
        }
    }

    for (int x = 0; x < AREA_DIMENSION; x++)
    {
        for (int y = 0; y < AREA_DIMENSION; y++)
        {
            if (Area::garden[x][y] == nullptr)
            {
                continue;
            }

            if ((*Area::garden[x][y]).repr() == ANT)
            {
                (*Area::garden[x][y]).breed();
            }   
        }
    }

    // kill off starving doodlebugs
    for (int x = 0; x < AREA_DIMENSION; x++)
    {
        for (int y = 0; y < AREA_DIMENSION; y++)
        {
            if (Area::garden[x][y] == nullptr)
            {
               continue;
            }
            
            if ((*Area::garden[x][y]).repr() == DOODLEBUG)
            {
                if ((*Area::garden[x][y]).is_starving())
                {
                    delete Area::garden[x][y];
                    Area::garden[x][y] = nullptr;
                }
            }
        }
    }
}

int Area::ant_count()
{
    int num_ants = 0;
    for (int x = 0; x < AREA_DIMENSION; x++)
    {
        for (int y = 0; y < AREA_DIMENSION; y++)
        {
            if (Area::garden[x][y] == nullptr)
            {
               continue;
            }
            
            if ((*Area::garden[x][y]).repr() == ANT)
            {
                num_ants += 1;
            }
        }
    }

    return num_ants;
}

int Area::doodlebug_count()
{
    int num_doodles = 0;
    for (int x = 0; x < AREA_DIMENSION; x++)
    {
        for (int y = 0; y < AREA_DIMENSION; y++)
        {
            if (Area::garden[x][y] == nullptr)
            {
               continue;
            }
            
            if ((*Area::garden[x][y]).repr() == DOODLEBUG)
            {
                num_doodles += 1;
            }
        }
    }

    return num_doodles;
}

/*--------------------------------- ORGANISM FUNCTIONS ---------------------------------*/

Organism::Organism(Area *current_state, int x, int y)
{
    this -> x = x;
    this -> y = y;
    this -> current_state = current_state;
    time_survived = current_state -> time_survived;
}

char Organism::repr()
{
    return 'a';
}

Coordinate Organism::get_empty_adjacent_cell(int x, int y)
{
    Coordinate default_location;
    std::vector<int> direction_order = get_shuffled_directions();

    for (int i = 0; i < direction_order.size(); i++)
    {
        Coordinate new_loc;
        
        int direction = direction_order[i];
        int temp_x = x;
        int temp_y = y;
        shift_coordinates(direction, temp_x, temp_y);

        if (is_valid_coordinate(temp_x, temp_y) && (*current_state).is_empty(temp_x, temp_y))
        {
            new_loc.x = temp_x;
            new_loc.y = temp_y;

            return new_loc;
        }
    }

    return default_location;
}

void Organism::move()
{
    time_survived += 1;
    time_until_breed -= 1;
    
    Coordinate valid_location = Organism::get_empty_adjacent_cell(x, y);
    if (valid_location.x == -1)
    {
        return;
    }
    
    current_state -> Area::garden[valid_location.x][valid_location.y] = this;
    current_state -> Area::garden[x][y] = nullptr;
    x = valid_location.x;
    y = valid_location.y;
}

/*--------------------------------- ANT FUNCTIONS ---------------------------------*/

Ant::Ant(Area *current_state, int x, int y) : Organism(current_state, x, y)
{
    time_until_breed = ANT_BREED_TIME;
}

void Ant::breed()
{
    if (time_until_breed > 0)
    {
        return;
    }
    
    Coordinate valid_cell = get_empty_adjacent_cell(x, y);
    if (valid_cell.x == -1)
    {
        return;
    }

    int new_x = valid_cell.x;
    int new_y = valid_cell.y;

    current_state -> Area::garden[new_x][new_y] = new Ant(current_state, new_x, new_y);
    time_until_breed = ANT_BREED_TIME;
}

/*--------------------------------- DOODLEBUG FUNCTIONS ---------------------------------*/

Doodlebug::Doodlebug(Area *current_state, int x, int y) : Organism(current_state, x, y)
{
    time_until_breed = DOODLEBUG_BREED_TIME;
}

void Doodlebug::move()
{
    time_survived += 1;
    // std::cout << '(' << x << ", " << y << ')';
    Coordinate ant_location = Doodlebug::locate_ant(x, y);

    if (ant_location.x == -1)
    {
        Organism::move();
        time_until_starve -= 1;
        return;
    }

    std::cout << '(' << x << ", " << y << ')';
    time_until_starve = DOODLEBUG_STARVE_TIME; // reset the starve time since bug has eaten
    delete current_state -> Area::garden[ant_location.x][ant_location.y];
    current_state -> Area::garden[ant_location.x][ant_location.y] = this;
    current_state -> Area::garden[x][y] = nullptr;
    x = ant_location.x;
    y = ant_location.y;
}

void Doodlebug::breed()
{
    if (time_until_breed > 0)
    {
        return;
    }
    
    Coordinate valid_cell = get_empty_adjacent_cell(x, y);
    if (valid_cell.x == -1)
    {
        return;
    }

    int new_x = valid_cell.x;
    int new_y = valid_cell.y;

    current_state -> Area::garden[new_x][new_y] = new Doodlebug(current_state, new_x, new_y);
    time_until_breed = DOODLEBUG_BREED_TIME;
}

Coordinate Doodlebug::locate_ant(int doodle_x, int doodle_y)
{
    // get first coordinates that have an ant
    Coordinate default_location;
    std::vector<int> direction_order = get_shuffled_directions();

    for (int i = 0; i < direction_order.size(); i++)
    {
        Coordinate ant_location;
        
        int direction = direction_order[i];
        int temp_x = doodle_x;
        int temp_y = doodle_y;
        shift_coordinates(direction, temp_x, temp_y);

        if (!is_valid_coordinate(temp_x, temp_y))
        {
            continue;
        }

        Organism *potential_org = current_state -> Area::garden[temp_x][temp_y];

        if (potential_org == nullptr)
        {
            continue;
        }
        
        if ((*potential_org).repr() == ANT)
        {
            ant_location.x = temp_x;
            ant_location.y = temp_y;

            return ant_location;
        }
    }

    return default_location;
}

int main()
{
    std::cout << "Starting simulation\n";

    Area area;
    area.populate_garden();
    area.print_garden();
    std::cout << '\n';

    int iteration = 1;
  
    area.advance_time_step();

    std::cout << "Iteration: " << iteration 
                << "; Ants: " << area.ant_count() 
                << "; Doodlebugs: " << area.doodlebug_count() << '\n';
    area.print_garden();
    std::cout << '\n';
    
    return 0;
}
