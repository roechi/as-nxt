const unsigned char A_STAR_LIST_SIZE = 127;

struct A_Star_Position
{
	char x;							// max 127
	char y;							// max 127
};

struct A_Star_Node
{
	A_Star_Position pos;
	unsigned short distance;		// max 65K
	unsigned char previous_node;	// max 255
	unsigned char id;
};

A_Star_Node a_star_open_list[A_STAR_LIST_SIZE];
A_Star_Node a_star_closed_list[A_STAR_LIST_SIZE];
A_Star_Node a_star_reversed_path[A_STAR_LIST_SIZE];

void a_star_calculate_path(A_Star_Position start, A_Star_Position target);

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
bool a_star_is_position_accessible(A_Star_Position position);

A_Star_Node a_star_get_node_with_minimum_distance();
void a_star_set_nearbours_to_open_list(A_Star_Node current_node);

void a_star_build_path(A_Star_Node target);


