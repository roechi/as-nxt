struct A_Star_Position
{
	char x;							// max 127
	char y;							// max 127
};

struct A_Star_Node
{
	bool is_active;
	A_Star_Position pos;
	short distance;		// max 65K
	unsigned char previous_node;	// max 255
	unsigned char id;
};

char A_STAR_SIZE_X = 0;
char A_STAR_SIZE_Y = 0;

void a_star_calculate_path(A_Star_Position a_star_start, A_Star_Position a_star_target, char space[][], const char size_x, const char size_y);

unsigned char a_star_get_new_id();

short a_star_is_in_open_list(A_Star_Node node);
short a_star_is_in_closed_list(A_Star_Node node);
bool a_star_add_to_open_list(A_Star_Node node);
bool a_star_add_to_closed_list(A_Star_Node node);
bool a_star_delete_from_open_list(A_Star_Node node);
bool a_star_delete_from_closed_list(A_Star_Node node);
unsigned char a_star_count_open_list_elements();
unsigned char a_star_count_closed_list_elements();
void a_star_clear_lists();
short a_star_get_open_list_index_by_id(unsigned char id);
short a_star_get_closed_list_index_by_id(unsigned char id);

bool a_star_compare_positions(A_Star_Position lhs, A_Star_Position rhs);
bool a_star_is_valid_position(A_Star_Position position);
bool a_star_is_position_accessible(A_Star_Position position, char space[][]);

A_Star_Node a_star_get_node_with_minimum_distance();
void a_star_set_nearbours_to_open_list(A_Star_Node current_node, char space[][]);

void a_star_build_path(A_Star_Node a_star_target);



#define A_STAR_NEARBOURS 4

unsigned char a_star_last_id;

A_Star_Node a_star_open_list[LIST_SIZE];
A_Star_Node a_star_closed_list[LIST_SIZE];
A_Star_Node a_star_reversed_path[LIST_SIZE];

unsigned char a_star_start_at;


void a_star_calculate_path(A_Star_Position a_star_start, A_Star_Position a_star_target, char space[][], const char size_x, const char size_y)
{
	A_STAR_SIZE_X = size_x;
	A_STAR_SIZE_Y = size_y;

	a_star_start_at = 0;
	a_star_last_id = 1;

	A_Star_Node start_node;
	start_node.is_active = true;
	start_node.pos = a_star_start;
	start_node.distance = 0;
	start_node.previous_node = 0;
	start_node.id = a_star_get_new_id();
	
	a_star_clear_lists();
	a_star_add_to_open_list(start_node);
	
	while (a_star_count_open_list_elements() > 0)
	{		
		A_Star_Node current = a_star_get_node_with_minimum_distance();
		
		if (a_star_compare_positions(current.pos, a_star_target))
		{		
			a_star_build_path(current);
			break;
		}
		else if (a_star_is_valid_position(current.pos))
		{
			a_star_add_to_closed_list(current);
			a_star_delete_from_open_list(current);
			
			a_star_set_nearbours_to_open_list(current, space);
		}
		else
		{
			TextOut(0, 0, "Error");
			Wait(1000);
		}
	}
}

unsigned char a_star_get_new_id()
{
	return a_star_last_id++;
}

short a_star_is_in_open_list(A_Star_Node node)
{
	short index = -1;
	
	for (unsigned char i = 0; i < LIST_SIZE && index == -1; ++i)
	{
		if (a_star_open_list[i].is_active && a_star_compare_positions(a_star_open_list[i].pos, node.pos))
			index = i;
	}

	return index;
}

short a_star_is_in_closed_list(A_Star_Node node)
{
	short index = -1;
	
	for (unsigned char i = 0; i < LIST_SIZE && index == -1; ++i)
	{
		if (a_star_closed_list[i].is_active && a_star_compare_positions(a_star_closed_list[i].pos, node.pos))
			index = i;
	}

	return index;
}

bool a_star_add_to_open_list(A_Star_Node node)
{
	bool is_set = false;
	
	for (unsigned char i = 0; i < LIST_SIZE && !is_set; ++i)
	{
		if (a_star_open_list[i].is_active == false || !a_star_is_valid_position(a_star_open_list[i].pos))
		{
			a_star_open_list[i].is_active = true;
			a_star_open_list[i].pos.x = node.pos.x;
			a_star_open_list[i].pos.y = node.pos.y;
			a_star_open_list[i].distance = node.distance;
			a_star_open_list[i].previous_node = node.previous_node;
			a_star_open_list[i].id = node.id;
			
			is_set = true;
		}
	}

	return is_set;
}

bool a_star_add_to_closed_list(A_Star_Node node)
{
	bool is_set = false;
	
	for (unsigned char i = 0; i < LIST_SIZE && !is_set; ++i)
	{
		if (a_star_closed_list[i].is_active == false || !a_star_is_valid_position(a_star_closed_list[i].pos))
		{
			a_star_closed_list[i] = node;
			is_set = true;
		}
	}

	return is_set;
}

bool a_star_delete_from_open_list(A_Star_Node node)
{
	short index = a_star_is_in_open_list(node);
	
	if (index != -1)
	{
		a_star_open_list[index].is_active = false;
		a_star_open_list[index].pos.x = -1;
		a_star_open_list[index].pos.y = -1;
		a_star_open_list[index].distance = 0;
		a_star_open_list[index].previous_node = 0;
	
		return true;
	}
	else
	{
		return false;
	}
}

bool a_star_delete_from_closed_list(A_Star_Node node)
{
	short index = a_star_is_in_closed_list(node);
	
	if (index != -1)
	{
		a_star_closed_list[index].is_active = false;
		a_star_closed_list[index].pos.x = -1;
		a_star_closed_list[index].pos.y = -1;
		a_star_closed_list[index].distance = 0;
		a_star_closed_list[index].previous_node = 0;
	
		return true;
	}
	else
	{
		return false;
	}
}

unsigned char a_star_count_open_list_elements()
{
	unsigned char counter = 0;
	
	for (unsigned char i = 0; i < LIST_SIZE; ++i)
	{
		if (a_star_open_list[i].is_active && a_star_is_valid_position(a_star_open_list[i].pos))
			++counter;
	}

	return counter;
}

unsigned char a_star_count_closed_list_elements()
{
	unsigned char counter = 0;
	
	for (unsigned char i = 0; i < LIST_SIZE; ++i)
	{
		if (a_star_closed_list[i].is_active && a_star_is_valid_position(a_star_closed_list[i].pos))
			++counter;
	}

	return counter;
}

void a_star_clear_lists()
{
	A_Star_Node default_node;
	default_node.is_active = false;
	default_node.pos.x = -1;
	default_node.pos.y = -1;
	default_node.distance = 0;
	default_node.previous_node = 0;
	
	for (unsigned char i = 0; i < LIST_SIZE; ++i)
	{
		a_star_open_list[i] = default_node;
		a_star_closed_list[i] = default_node;
	}
}

short a_star_get_open_list_index_by_id(unsigned char id)
{
	short index = -1;
	
	for (unsigned char i = 0; i < LIST_SIZE && index == -1; ++i)
	{
		if (a_star_open_list[i].id == id)
			index = i;
	}
	
	return index;
}

short a_star_get_closed_list_index_by_id(unsigned char id)
{
	short index = -1;
	
	for (unsigned char i = 0; i < LIST_SIZE && index == -1; ++i)
	{
		if (a_star_closed_list[i].id == id)
			index = i;
	}
	
	return index;
}

bool a_star_compare_positions(A_Star_Position lhs, A_Star_Position rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool a_star_is_valid_position(A_Star_Position position)
{
	return position.x != -1 && position.y != -1 &&
		   position.x < A_STAR_SIZE_X && position.y < A_STAR_SIZE_Y;
}

bool a_star_is_position_accessible(A_Star_Position position, char space[][])
{
	if (!a_star_is_valid_position(position))
		return false;
	else
	{
		char field_value = space[position.x][position.y];
		
		if (field_value == EXPLORED || field_value == TARGET)
			return true;
		else
			return false;
	}
}


A_Star_Node a_star_get_node_with_minimum_distance()
{
	short index = -1;
	unsigned short min_distance = -1;	// Max unsigned short
	
	for (unsigned char i = 0; i < LIST_SIZE; ++i)
	{	
		if (a_star_open_list[i].is_active && a_star_is_valid_position(a_star_open_list[i].pos))
		{
			if (min_distance > a_star_open_list[i].distance)
			{			
				min_distance = a_star_open_list[i].distance;
				index = i;
			}
		}
	}

	if (index == -1)
	{
		A_Star_Node invalid_node;
		invalid_node.is_active = true;
		invalid_node.pos.x = -1;
		invalid_node.pos.y = -1;
		
		return invalid_node;
	}
	else
	{
		return a_star_open_list[index];
	}
}

void a_star_set_nearbours_to_open_list(A_Star_Node current_node, char space[][])
{
	if (A_STAR_NEARBOURS == 4)
	{
		char offsets[] = { 0, -1, -1, 0, 1, 0, 0, 1 };
		
		for (unsigned char i = 0; i < 8; i += 2)
		{
			A_Star_Node tmp_node;
			tmp_node.is_active = true;
			tmp_node.pos.x = current_node.pos.x + offsets[i];
			tmp_node.pos.y = current_node.pos.y + offsets[i + 1];
			
			if (!a_star_is_valid_position(tmp_node.pos))	// Position nicht valide (Ausserhalb der Karte)
				continue;
				
			if (!a_star_is_position_accessible(tmp_node.pos, space))
				continue;
			
			if (a_star_is_in_closed_list(tmp_node) != -1)		// In closed List vorhanden
				continue;
			
			tmp_node.distance = current_node.distance + 1;
			
			short index_in_open_list = a_star_is_in_open_list(tmp_node);
			if (index_in_open_list == -1)		// Nicht in Open List vorhanden
			{
				tmp_node.id = a_star_get_new_id();
				tmp_node.previous_node = current_node.id;
				a_star_add_to_open_list(tmp_node);
			}
			else if (a_star_open_list[index_in_open_list].distance > tmp_node.distance) // Besserer Weg gefunden
			{
				a_star_open_list[index_in_open_list].distance = tmp_node.distance;
				a_star_open_list[index_in_open_list].previous_node = current_node.id;
			}
		}
	}
	else
	{
		// NOT IMPLEMENTED
	}
}

void a_star_build_path(A_Star_Node a_star_target)
{
	unsigned char index = 0;
	A_Star_Node current_node = a_star_target;
	a_star_reversed_path[index++] = current_node;
	
	while (current_node.previous_node != 0)
	{
		
		A_Star_Node tmp_node = a_star_get_closed_list_index_by_id(current_node.previous_node);
		current_node.previous_node = tmp_node.previous_node;
		current_node.id = tmp_node.id;
		current_node.pos.x = tmp_node.pos.x;
		current_node.pos.y = tmp_node.pos.y;
		
		a_star_reversed_path[index].pos.x = current_node.pos.x;
		a_star_reversed_path[index].pos.y = current_node.pos.y;
		
		index++;
	}
	
	a_star_start_at = index - 1;
	
	for (unsigned char i = index; i < LIST_SIZE; ++i)
	{
		a_star_reversed_path[i].id = 0;
	}
}
