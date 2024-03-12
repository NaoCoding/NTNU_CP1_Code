#include <gtk/gtk.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include "diceRolls.h"

GtkWidget* main_gui, *start_message_label,*start_game_button;
GtkWidget* start_screen_box, *exit_game_button,*start_screen_setting_button;
GtkWidget* author_label;
GtkWidget * setting_screen_fixed,*setting_gamename_label,*setting_back_button;
GtkWidget *setting_label;
GtkWidget *story_skip_button,*story_message_label;
GtkWidget *story_screen_fixed,*story_next_button;
GtkWidget *maingame_fixed,*dice_num_selector;
GtkWidget *dice_num_label, *dice_face_selector_minus1;
GtkWidget * dice_face_label, * dice_face_selector, *dice_num1_selector;
GtkWidget *dice_face_selector_minus10,*dice_face_selector_add10;
GtkWidget *dice_add_sum_selector,*dice_add_sum1_selector;
GtkWidget *dice_sum_add_label;
GtkWidget *dice_keep_selector, *dice_keep1_selector;
GtkWidget *dice_keep_label;
GtkWidget *dice_highest_selector, *dice_highest1_selector;
GtkWidget *dice_highest_label;
GtkWidget *dice_lowest_selector, *dice_lowest1_selector;
GtkWidget *dice_lowest_label;
GtkWidget *dice_setting_done_button;
GtkWidget *choose_dice_fixed;
GtkWidget *dice_button0;
GtkWidget *dice_button1;
GtkWidget *dice_button2;
GtkWidget *dice_button3;
GtkWidget *dice_button4;
GtkWidget *dice_button5;
GtkWidget *dice_button6;
GtkWidget *dice_button7;
GtkWidget *dice_button8;
GtkWidget *dice_button9;
GtkWidget *dice_status_label0;
GtkWidget *dice_status_label1;
GtkWidget *dice_status_label2;
GtkWidget *dice_status_label3;
GtkWidget *dice_status_label4;
GtkWidget *dice_status_label5;
GtkWidget *dice_status_label6;
GtkWidget *dice_status_label7;
GtkWidget *dice_status_label8;
GtkWidget *dice_status_label9;
GtkWidget *no_dice_label,*roll_again_button,*dices_setting_title,*next_button;
GtkWidget *result_display_fixed,*result_label,*answer_total_label;
#include "diceRolls.h"
PangoFontDescription *font_25;
PangoFontDescription*font_40, *font_20;
PangoFontDescription *font_10;
PangoFontDescription *font_23, *font_15;


static void setting_screen_cmd(GtkWidget * widget , gpointer data);
static void back_to_main_menu_cmd(GtkWidget * widget , gpointer data);
static void start_game_cmd(GtkWidget * widget , gpointer data);
static void story_page_changed(GtkWidget *widget , gpointer data);
static void story_end_cmd(GtkWidget *widget , gpointer data);
static void game_start();
static void change_dice_num_cmd();
static void change_dice_num1_cmd();
static void change_dice_keep_cmd();
static void change_dice_keep1_cmd();
static void change_dice_face_cmd(int cmd);
static void change_dice_face1_cmd();
static void change_dice_face10_cmd();
static void change_dice_facem10_cmd();
static void change_dice_add_sum_cmd();
static void change_dice_add_sum1_cmd();
static void change_dice_facem1_cmd();
static void change_dice_highest_cmd();
static void change_dice_highest1_cmd();
static void change_dice_lowest_cmd();
static void change_dice_lowest1_cmd();
static void play_again_cmd();
static void play_again_cmd1();
static void choose_dice_0();
static void choose_dice_1();
static void choose_dice_2();
static void choose_dice_3();
static void choose_dice_4();
static void choose_dice_5();
static void choose_dice_6();
static void choose_dice_7();
static void choose_dice_8();
static void choose_dice_9();
static void dice_setting_done();
static void select_high();
static void select_low();
static void result_display();
int story_page = 0, story_skip_times = 0;
int dice_add_sum = 0;
int dice_num = 1,dice_face = 2;
int dice_keep = 0, dice_highest = 0, dice_lowest = 0;
char dice_add_sum_string[3], dice_highest_string[3],dice_lowest_string[3];
char dice_keep_string[2];
char dice_num_string[2], dice_face_string[3];
char * story_skip_words = "Skip Story";
char * dice_status[10];
int dice_result[10];
int dice_choosed[10],num_of_dice_choosed=0;
char dice_result_string[10][3];

int main(int argc ,char* argv[]){

	srand(time(NULL));
	gtk_init(&argc,&argv);
	
	main_gui = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(main_gui),800,600);
	gtk_window_set_title(GTK_WINDOW(main_gui), "Dice Simulator");
	start_screen_box = gtk_fixed_new();


	start_message_label = gtk_label_new("Dice Simulator");
	author_label = gtk_label_new("Author : 41247001S");
	//gtk_label_set_text(GTK_LABEL(start_message_label),"Messages");

	start_game_button = gtk_button_new_with_label("Start the game !");
	start_screen_setting_button = gtk_button_new_with_label("Setting");
	exit_game_button = gtk_button_new_with_label("Exit!");
	

	font_40 = pango_font_description_from_string("Times New Roman");
	pango_font_description_set_size(font_40,40*PANGO_SCALE);
	gtk_widget_modify_font(start_message_label,font_40);


	font_15 = pango_font_description_from_string("Times New Roman");
	pango_font_description_set_size(font_15,20*PANGO_SCALE);
	font_20 = pango_font_description_from_string("Times New Roman");
	pango_font_description_set_size(font_20,20*PANGO_SCALE);
	gtk_widget_modify_font(start_game_button,font_20);
	gtk_widget_modify_font(exit_game_button,font_20);
	gtk_widget_modify_font(start_screen_setting_button,font_20);
	gtk_widget_modify_font(author_label,font_20);

	gtk_widget_set_size_request(start_game_button,300,80);
	gtk_widget_set_size_request(exit_game_button,300,80);
	gtk_widget_set_size_request(start_screen_setting_button,300,80);

	gtk_container_add(GTK_CONTAINER(main_gui),start_screen_box);

	gtk_fixed_put(GTK_FIXED(start_screen_box),start_message_label,200,90);
	gtk_fixed_put(GTK_FIXED(start_screen_box),author_label,480,530);
	gtk_fixed_put(GTK_FIXED(start_screen_box),start_game_button,250,210);
	gtk_fixed_put(GTK_FIXED(start_screen_box),exit_game_button,250,410);
	gtk_fixed_put(GTK_FIXED(start_screen_box),start_screen_setting_button,250,310);

	g_signal_connect(main_gui,"delete-event",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(exit_game_button,"clicked",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(start_game_button,"clicked",G_CALLBACK(start_game_cmd),NULL);
	g_signal_connect(start_screen_setting_button,"clicked",G_CALLBACK(setting_screen_cmd),NULL);


	gtk_widget_show_all(main_gui);
	gtk_main();


	return 0;

}



static void result_display(){

	if(dice_lowest+dice_highest+dice_keep==0){
		for(int i=0;i<dice_num;i++) dice_choosed[i] = 3;
	}

	int64_t answer_total = dice_add_sum;
	for(int i=0;i<dice_num;i++){
		if(dice_choosed[i]) answer_total += dice_result[i];
	}


	gtk_container_remove(GTK_CONTAINER(main_gui),choose_dice_fixed);
	result_display_fixed = gtk_fixed_new();
	roll_again_button = gtk_button_new_with_label("Play Again!");
	result_label = gtk_label_new("Answer = ");
	gtk_widget_modify_font(roll_again_button,font_20);
	gtk_widget_modify_font(result_label,font_25);

	char answer_total_string[10];
	sprintf(answer_total_string, "%d", answer_total);
	answer_total_label = gtk_label_new(answer_total_string);
	gtk_widget_modify_font(answer_total_label,font_25);
	gtk_fixed_put(GTK_FIXED(result_display_fixed),answer_total_label,300,65);

	gtk_widget_set_size_request(roll_again_button,160,80);

	gtk_fixed_put(GTK_FIXED(result_display_fixed),result_label,100,65);
	gtk_fixed_put(GTK_FIXED(result_display_fixed),roll_again_button,550,50);
	g_signal_connect(roll_again_button,"clicked",G_CALLBACK(play_again_cmd1),NULL);

	dice_status_label0 = gtk_label_new(dice_status[0]);
	dice_status_label1 = gtk_label_new(dice_status[1]);
	dice_status_label2 = gtk_label_new(dice_status[2]);
	dice_status_label3 = gtk_label_new(dice_status[3]);
	dice_status_label4 = gtk_label_new(dice_status[4]);
	dice_status_label5 = gtk_label_new(dice_status[5]);
	dice_status_label6 = gtk_label_new(dice_status[6]);
	dice_status_label7 = gtk_label_new(dice_status[7]);
	dice_status_label8 = gtk_label_new(dice_status[8]);
	dice_status_label9 = gtk_label_new(dice_status[9]);


	sprintf(dice_result_string[0], "%d", dice_result[0]);
	dice_button0 = gtk_button_new_with_label(dice_result_string[0]);
	sprintf(dice_result_string[1], "%d", dice_result[1]);
	dice_button1 = gtk_button_new_with_label(dice_result_string[1]);
	sprintf(dice_result_string[2], "%d", dice_result[2]);
	dice_button2 = gtk_button_new_with_label(dice_result_string[2]);
	sprintf(dice_result_string[3], "%d", dice_result[3]);
	dice_button3 = gtk_button_new_with_label(dice_result_string[3]);
	sprintf(dice_result_string[4], "%d", dice_result[4]);
	dice_button4 = gtk_button_new_with_label(dice_result_string[4]);
	sprintf(dice_result_string[5], "%d", dice_result[5]);
	dice_button5 = gtk_button_new_with_label(dice_result_string[5]);
	sprintf(dice_result_string[6], "%d", dice_result[6]);
	dice_button6 = gtk_button_new_with_label(dice_result_string[6]);
	sprintf(dice_result_string[7], "%d", dice_result[7]);
	dice_button7 = gtk_button_new_with_label(dice_result_string[7]);
	sprintf(dice_result_string[8], "%d", dice_result[8]);
	dice_button8 = gtk_button_new_with_label(dice_result_string[8]);
	sprintf(dice_result_string[9], "%d", dice_result[9]);
	dice_button9 = gtk_button_new_with_label(dice_result_string[9]);

	gtk_widget_modify_font(dice_status_label0,font_20);
	gtk_widget_modify_font(dice_status_label1,font_20);
	gtk_widget_modify_font(dice_status_label2,font_20);
	gtk_widget_modify_font(dice_status_label3,font_20);
	gtk_widget_modify_font(dice_status_label4,font_20);
	gtk_widget_modify_font(dice_status_label5,font_20);
	gtk_widget_modify_font(dice_status_label6,font_20);
	gtk_widget_modify_font(dice_status_label7,font_20);
	gtk_widget_modify_font(dice_status_label8,font_20);
	gtk_widget_modify_font(dice_status_label9,font_20);

	gtk_widget_modify_font(dice_button0,font_20);
	gtk_widget_modify_font(dice_button1,font_20);
	gtk_widget_modify_font(dice_button2,font_20);
	gtk_widget_modify_font(dice_button3,font_20);
	gtk_widget_modify_font(dice_button4,font_20);
	gtk_widget_modify_font(dice_button5,font_20);
	gtk_widget_modify_font(dice_button6,font_20);
	gtk_widget_modify_font(dice_button7,font_20);
	gtk_widget_modify_font(dice_button8,font_20);
	gtk_widget_modify_font(dice_button9,font_20);

	gtk_widget_set_size_request(dice_button0,100,100);
	gtk_widget_set_size_request(dice_button1,100,100);
	gtk_widget_set_size_request(dice_button2,100,100);
	gtk_widget_set_size_request(dice_button3,100,100);
	gtk_widget_set_size_request(dice_button4,100,100);
	gtk_widget_set_size_request(dice_button5,100,100);
	gtk_widget_set_size_request(dice_button6,100,100);
	gtk_widget_set_size_request(dice_button7,100,100);
	gtk_widget_set_size_request(dice_button8,100,100);
	gtk_widget_set_size_request(dice_button9,100,100);

	if(dice_choosed[0]){gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_button0,70,200);
	gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_status_label0,70,300+15);}
	if(dice_choosed[1]){gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_button1,210,200);
	gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_status_label1,210,300+15);}
	if(dice_choosed[2]){gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_button2,350,200);
	gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_status_label2,350,300+15);}
	if(dice_choosed[3]){gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_button3,490,200);
	gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_status_label3,490,300+15);}
	if(dice_choosed[4]){gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_button4,630,200);
	gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_status_label4,630,300+15);}
	if(dice_choosed[5]){gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_button5,70,400);
	gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_status_label5,70,500+15);}
	if(dice_choosed[6]){gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_button6,210,400);
	gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_status_label6,210,500+15);}
	if(dice_choosed[7]){gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_button7,350,400);
	gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_status_label7,350,500+15);}
	if(dice_choosed[8]){gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_button8,490,400);
	gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_status_label8,490,500+15);}
	if(dice_choosed[9]){gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_button9,630,400);
	gtk_fixed_put(GTK_FIXED(result_display_fixed),dice_status_label9,630,500+15);}




	gtk_container_add(GTK_CONTAINER(main_gui),result_display_fixed);
	gtk_widget_show_all(main_gui);

}


static void dice_setting_done(){


	gtk_container_remove(GTK_CONTAINER(main_gui),maingame_fixed);
	
	
	choose_dice_fixed = gtk_fixed_new();
	font_25 = pango_font_description_from_string("Times New Roman");
	pango_font_description_set_size(font_25,25*PANGO_SCALE);
	dices_setting_title = gtk_label_new("Preview Dice and Choose Dice");
	gtk_widget_modify_font(dices_setting_title,font_25);
	gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dices_setting_title,80,65);
	next_button = gtk_button_new_with_label(" Next ");
	gtk_widget_modify_font(next_button,font_20);
	gtk_widget_set_size_request(next_button,120,50);
	gtk_fixed_put(GTK_FIXED(choose_dice_fixed),next_button,620,60);
	g_signal_connect(next_button,"clicked",G_CALLBACK(result_display),NULL);


	for(int i=0;i<dice_num;i++) dice_result[i] = dice____(dice_face);

	sprintf(dice_result_string[0], "%d", dice_result[0]);
	dice_button0 = gtk_button_new_with_label(dice_result_string[0]);
	sprintf(dice_result_string[1], "%d", dice_result[1]);
	dice_button1 = gtk_button_new_with_label(dice_result_string[1]);
	sprintf(dice_result_string[2], "%d", dice_result[2]);
	dice_button2 = gtk_button_new_with_label(dice_result_string[2]);
	sprintf(dice_result_string[3], "%d", dice_result[3]);
	dice_button3 = gtk_button_new_with_label(dice_result_string[3]);
	sprintf(dice_result_string[4], "%d", dice_result[4]);
	dice_button4 = gtk_button_new_with_label(dice_result_string[4]);
	sprintf(dice_result_string[5], "%d", dice_result[5]);
	dice_button5 = gtk_button_new_with_label(dice_result_string[5]);
	sprintf(dice_result_string[6], "%d", dice_result[6]);
	dice_button6 = gtk_button_new_with_label(dice_result_string[6]);
	sprintf(dice_result_string[7], "%d", dice_result[7]);
	dice_button7 = gtk_button_new_with_label(dice_result_string[7]);
	sprintf(dice_result_string[8], "%d", dice_result[8]);
	dice_button8 = gtk_button_new_with_label(dice_result_string[8]);
	sprintf(dice_result_string[9], "%d", dice_result[9]);
	dice_button9 = gtk_button_new_with_label(dice_result_string[9]);

	dice_status_label0 = gtk_label_new(dice_status[0]);
	dice_status_label1 = gtk_label_new(dice_status[1]);
	dice_status_label2 = gtk_label_new(dice_status[2]);
	dice_status_label3 = gtk_label_new(dice_status[3]);
	dice_status_label4 = gtk_label_new(dice_status[4]);
	dice_status_label5 = gtk_label_new(dice_status[5]);
	dice_status_label6 = gtk_label_new(dice_status[6]);
	dice_status_label7 = gtk_label_new(dice_status[7]);
	dice_status_label8 = gtk_label_new(dice_status[8]);
	dice_status_label9 = gtk_label_new(dice_status[9]);


	gtk_widget_modify_font(dice_status_label0,font_20);
	gtk_widget_modify_font(dice_status_label1,font_20);
	gtk_widget_modify_font(dice_status_label2,font_20);
	gtk_widget_modify_font(dice_status_label3,font_20);
	gtk_widget_modify_font(dice_status_label4,font_20);
	gtk_widget_modify_font(dice_status_label5,font_20);
	gtk_widget_modify_font(dice_status_label6,font_20);
	gtk_widget_modify_font(dice_status_label7,font_20);
	gtk_widget_modify_font(dice_status_label8,font_20);
	gtk_widget_modify_font(dice_status_label9,font_20);


	gtk_widget_modify_font(dice_button0,font_20);
	gtk_widget_modify_font(dice_button1,font_20);
	gtk_widget_modify_font(dice_button2,font_20);
	gtk_widget_modify_font(dice_button3,font_20);
	gtk_widget_modify_font(dice_button4,font_20);
	gtk_widget_modify_font(dice_button5,font_20);
	gtk_widget_modify_font(dice_button6,font_20);
	gtk_widget_modify_font(dice_button7,font_20);
	gtk_widget_modify_font(dice_button8,font_20);
	gtk_widget_modify_font(dice_button9,font_20);

	gtk_widget_set_size_request(dice_button0,100,100);
	gtk_widget_set_size_request(dice_button1,100,100);
	gtk_widget_set_size_request(dice_button2,100,100);
	gtk_widget_set_size_request(dice_button3,100,100);
	gtk_widget_set_size_request(dice_button4,100,100);
	gtk_widget_set_size_request(dice_button5,100,100);
	gtk_widget_set_size_request(dice_button6,100,100);
	gtk_widget_set_size_request(dice_button7,100,100);
	gtk_widget_set_size_request(dice_button8,100,100);
	gtk_widget_set_size_request(dice_button9,100,100);


	if(dice_num==0){
		no_dice_label = gtk_label_new("No Dice!"); 
		gtk_widget_modify_font(no_dice_label,font_40);
		gtk_fixed_put(GTK_FIXED(choose_dice_fixed),no_dice_label,280,230);
		roll_again_button = gtk_button_new_with_label("Play Again!");
		gtk_widget_modify_font(roll_again_button,font_20);
		gtk_widget_set_size_request(roll_again_button,160,80);
		gtk_fixed_put(GTK_FIXED(choose_dice_fixed),roll_again_button,550,450);
		g_signal_connect(roll_again_button,"clicked",G_CALLBACK(play_again_cmd),NULL);

	}
	if(dice_num>0){gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_button0,70,200);
	gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_status_label0,70,300+15);}
	if(dice_num>1){gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_button1,210,200);
	gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_status_label1,210,300+15);}
	if(dice_num>2){gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_button2,350,200);
	gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_status_label2,350,300+15);}
	if(dice_num>3){gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_button3,490,200);
	gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_status_label3,490,300+15);}
	if(dice_num>4){gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_button4,630,200);
	gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_status_label4,630,300+15);}
	if(dice_num>5){gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_button5,70,400);
	gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_status_label5,70,500+15);}
	if(dice_num>6){gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_button6,210,400);
	gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_status_label6,210,500+15);}
	if(dice_num>7){gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_button7,350,400);
	gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_status_label7,350,500+15);}
	if(dice_num>8){gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_button8,490,400);
	gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_status_label8,490,500+15);}
	if(dice_num>9){gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_button9,630,400);
	gtk_fixed_put(GTK_FIXED(choose_dice_fixed),dice_status_label9,630,500+15);}
	select_high();
	select_low();

	g_signal_connect(dice_button0,"clicked",G_CALLBACK(choose_dice_0),NULL);
	g_signal_connect(dice_button1,"clicked",G_CALLBACK(choose_dice_1),NULL);
	g_signal_connect(dice_button2,"clicked",G_CALLBACK(choose_dice_2),NULL);
	g_signal_connect(dice_button3,"clicked",G_CALLBACK(choose_dice_3),NULL);
	g_signal_connect(dice_button4,"clicked",G_CALLBACK(choose_dice_4),NULL);
	g_signal_connect(dice_button5,"clicked",G_CALLBACK(choose_dice_5),NULL);
	g_signal_connect(dice_button6,"clicked",G_CALLBACK(choose_dice_6),NULL);
	g_signal_connect(dice_button7,"clicked",G_CALLBACK(choose_dice_7),NULL);
	g_signal_connect(dice_button8,"clicked",G_CALLBACK(choose_dice_8),NULL);
	g_signal_connect(dice_button9,"clicked",G_CALLBACK(choose_dice_9),NULL);

	gtk_container_add(GTK_CONTAINER(main_gui),choose_dice_fixed);
	gtk_widget_show_all(main_gui);
	


}

static void select_high(){

	int j=0;
	for(int i=0;i<dice_highest;i++){
		
		int j = high_calcl(0,dice_choosed,dice_num,dice_result);
		dice_choosed[j] = 2;
		dice_status[j] = "Highest";
		if(j==0)gtk_label_set_text(GTK_LABEL(dice_status_label0),dice_status[j]);
		if(j==1)gtk_label_set_text(GTK_LABEL(dice_status_label1),dice_status[j]);
		if(j==2)gtk_label_set_text(GTK_LABEL(dice_status_label2),dice_status[j]);
		if(j==3)gtk_label_set_text(GTK_LABEL(dice_status_label3),dice_status[j]);
		if(j==4)gtk_label_set_text(GTK_LABEL(dice_status_label4),dice_status[j]);
		if(j==5)gtk_label_set_text(GTK_LABEL(dice_status_label5),dice_status[j]);
		if(j==6)gtk_label_set_text(GTK_LABEL(dice_status_label6),dice_status[j]);
		if(j==7)gtk_label_set_text(GTK_LABEL(dice_status_label7),dice_status[j]);
		if(j==8)gtk_label_set_text(GTK_LABEL(dice_status_label8),dice_status[j]);
		if(j==9)gtk_label_set_text(GTK_LABEL(dice_status_label9),dice_status[j]);
	}



}

static void select_low(){

	int j=0;
	for(int i=0;i<dice_lowest;i++){
		j = low_calcl(0,dice_choosed,dice_num,dice_result);
		dice_choosed[j] = 2;
		dice_status[j] = "Lowest";
		if(j==0)gtk_label_set_text(GTK_LABEL(dice_status_label0),dice_status[j]);
		if(j==1)gtk_label_set_text(GTK_LABEL(dice_status_label1),dice_status[j]);
		if(j==2)gtk_label_set_text(GTK_LABEL(dice_status_label2),dice_status[j]);
		if(j==3)gtk_label_set_text(GTK_LABEL(dice_status_label3),dice_status[j]);
		if(j==4)gtk_label_set_text(GTK_LABEL(dice_status_label4),dice_status[j]);
		if(j==5)gtk_label_set_text(GTK_LABEL(dice_status_label5),dice_status[j]);
		if(j==6)gtk_label_set_text(GTK_LABEL(dice_status_label6),dice_status[j]);
		if(j==7)gtk_label_set_text(GTK_LABEL(dice_status_label7),dice_status[j]);
		if(j==8)gtk_label_set_text(GTK_LABEL(dice_status_label8),dice_status[j]);
		if(j==9)gtk_label_set_text(GTK_LABEL(dice_status_label9),dice_status[j]);
	}



}

static void choose_dice_0(){

	if(dice_choosed[0]==1){
		dice_choosed[0] = 0;
		num_of_dice_choosed -= 1;
		dice_status[0] = " ";gtk_label_set_text(GTK_LABEL(dice_status_label0),dice_status[0]);
	}
	else if(num_of_dice_choosed<dice_keep&&dice_choosed[0]==0){
		num_of_dice_choosed+=1;
		dice_choosed[0] = 1;
		dice_status[0] = "Choosed";gtk_label_set_text(GTK_LABEL(dice_status_label0),dice_status[0]);
	}

}

static void choose_dice_1(){

if(dice_choosed[1]==1){
		dice_choosed[1] = 0;
		num_of_dice_choosed -= 1;
		dice_status[1] = "  ";gtk_label_set_text(GTK_LABEL(dice_status_label1),dice_status[1]);
	}
	else if(num_of_dice_choosed<dice_keep&&dice_choosed[1]==0){
		num_of_dice_choosed+=1;
		dice_choosed[1] = 1;
		dice_status[1] = "Choosed";gtk_label_set_text(GTK_LABEL(dice_status_label1),dice_status[1]);
	}

}
static void choose_dice_2(){

	if(dice_choosed[2]==1){
		dice_choosed[2] = 0;
		num_of_dice_choosed -= 1;
		dice_status[2] = "  ";gtk_label_set_text(GTK_LABEL(dice_status_label2),dice_status[2]);
	}
	else if(num_of_dice_choosed<dice_keep&&dice_choosed[2]==0){
		num_of_dice_choosed+=1;
		dice_choosed[2] = 1;
		dice_status[2] = "Choosed";gtk_label_set_text(GTK_LABEL(dice_status_label2),dice_status[2]);
	}

}
static void choose_dice_3(){

	if(dice_choosed[3]==1){
		dice_choosed[3] = 0;
		num_of_dice_choosed -= 1;
		dice_status[3] = "  ";gtk_label_set_text(GTK_LABEL(dice_status_label3),dice_status[3]);
	}
	else if(num_of_dice_choosed<dice_keep&&dice_choosed[3]==0){
		num_of_dice_choosed+=1;
		dice_choosed[3] = 1;
		dice_status[3] = "Choosed";gtk_label_set_text(GTK_LABEL(dice_status_label3),dice_status[3]);
	}

}
static void choose_dice_4(){

	if(dice_choosed[4]==1){
		dice_choosed[4] = 0;
		num_of_dice_choosed -= 1;
		dice_status[4] = "  ";gtk_label_set_text(GTK_LABEL(dice_status_label4),dice_status[4]);
	}
	else if(num_of_dice_choosed<dice_keep&&dice_choosed[4]==0){
		num_of_dice_choosed+=1;
		dice_choosed[4] = 1;
		dice_status[4] = "Choosed";gtk_label_set_text(GTK_LABEL(dice_status_label4),dice_status[4]);
	}

}
static void choose_dice_5(){

	if(dice_choosed[5]==1){
		dice_choosed[5] = 0;
		num_of_dice_choosed -= 1;
		dice_status[5] = "   ";gtk_label_set_text(GTK_LABEL(dice_status_label5),dice_status[5]);
	}
	else if(num_of_dice_choosed<dice_keep&&dice_choosed[5]==0){
		num_of_dice_choosed+=1;
		dice_choosed[5] = 1;
		dice_status[5] = "Choosed";gtk_label_set_text(GTK_LABEL(dice_status_label5),dice_status[5]);
	}

}
static void choose_dice_6(){

	if(dice_choosed[6]==1){
		dice_choosed[6] = 0;
		num_of_dice_choosed -= 1;
		dice_status[6] = "  ";gtk_label_set_text(GTK_LABEL(dice_status_label6),dice_status[6]);
	}
	else if(num_of_dice_choosed<dice_keep&&dice_choosed[6]==0){
		num_of_dice_choosed+=1;
		dice_choosed[6] = 1;
		dice_status[6] = "Choosed";gtk_label_set_text(GTK_LABEL(dice_status_label6),dice_status[6]);
	}

}
static void choose_dice_7(){

	if(dice_choosed[7]==1){
		dice_choosed[7] = 0;
		num_of_dice_choosed -= 1;
		dice_status[7] = "  ";gtk_label_set_text(GTK_LABEL(dice_status_label7),dice_status[7]);
	}
	else if(num_of_dice_choosed<dice_keep&&dice_choosed[7]==0){
		num_of_dice_choosed+=1;
		dice_choosed[7] = 1;
		dice_status[7] = "Choosed";gtk_label_set_text(GTK_LABEL(dice_status_label7),dice_status[7]);
	}

}
static void choose_dice_8(){

	if(dice_choosed[8]==1){
		dice_choosed[8] = 0;
		num_of_dice_choosed -= 1;
		dice_status[8] = "  ";gtk_label_set_text(GTK_LABEL(dice_status_label8),dice_status[8]);
	}
	else if(num_of_dice_choosed<dice_keep&&dice_choosed[8]==0){
		num_of_dice_choosed+=1;
		dice_choosed[8] = 1;
		dice_status[8] = "Choosed";gtk_label_set_text(GTK_LABEL(dice_status_label8),dice_status[8]);
	}

}
static void choose_dice_9(){

	if(dice_choosed[9]==1){
		dice_choosed[9] = 0;
		num_of_dice_choosed -= 1;
		dice_status[9] = "  ";gtk_label_set_text(GTK_LABEL(dice_status_label9),dice_status[9]);
	}
	else if(num_of_dice_choosed<dice_keep&&dice_choosed[9]==0){
		num_of_dice_choosed+=1;
		dice_choosed[9] = 1;
		dice_status[9] = "Choosed";gtk_label_set_text(GTK_LABEL(dice_status_label9),dice_status[9]);
	}

}



void game_start(){

	for(int i=0;i<10;i++){
		dice_choosed[i] = 0;
		dice_status[i] = "      ";
	}

	num_of_dice_choosed=0;
	maingame_fixed = gtk_fixed_new();


	sprintf(dice_num_string, "%d", dice_num);
	dice_num_selector = gtk_button_new_with_label(dice_num_string);
	dice_num1_selector = gtk_button_new_with_label("-1");
	dice_num_label = gtk_label_new("Number of dice to be rolled");

	sprintf(dice_keep_string, "%d", dice_keep);
	dice_keep_selector = gtk_button_new_with_label(dice_keep_string);
	dice_keep1_selector = gtk_button_new_with_label("-1");
	dice_keep_label = gtk_label_new("Number of dice to be kept");


	sprintf(dice_face_string, "%d", dice_face);
	dice_face_selector = gtk_button_new_with_label(dice_face_string);
	dice_face_selector_minus1 = gtk_button_new_with_label("-1");
	dice_face_selector_add10 = gtk_button_new_with_label("+10");
	dice_face_selector_minus10 = gtk_button_new_with_label("-10");
	dice_face_label = gtk_label_new("Number of face of each dice");

	sprintf(dice_add_sum_string,"%d",dice_add_sum);
	dice_sum_add_label = gtk_label_new("Number to be added to the sum");
	dice_add_sum_selector = gtk_button_new_with_label(dice_add_sum_string);
	dice_add_sum1_selector = gtk_button_new_with_label("-1");

	sprintf(dice_lowest_string,"%d",dice_lowest);
	dice_lowest_label = gtk_label_new("Number to be kept from lowest");
	dice_lowest_selector = gtk_button_new_with_label(dice_lowest_string);
	dice_lowest1_selector = gtk_button_new_with_label("-1");

	sprintf(dice_highest_string,"%d",dice_highest);
	dice_highest_label = gtk_label_new("Number to be kept from highest");
	dice_highest_selector = gtk_button_new_with_label(dice_highest_string);
	dice_highest1_selector = gtk_button_new_with_label("-1");

	dice_setting_done_button = gtk_button_new_with_label("Roll the Dice!");


	font_15 = pango_font_description_from_string("Times New Roman");
	pango_font_description_set_size(font_15,20*PANGO_SCALE);
	font_20 = pango_font_description_from_string("Times New Roman");
	pango_font_description_set_size(font_20,20*PANGO_SCALE);

	gtk_widget_modify_font(dice_num_label,font_15);
	gtk_widget_modify_font(dice_sum_add_label,font_15);
	gtk_widget_modify_font(dice_num_selector,font_20);
	gtk_widget_modify_font(dice_num1_selector,font_20);
	gtk_widget_modify_font(dice_face_label,font_15);
	gtk_widget_modify_font(dice_face_selector,font_20);
	gtk_widget_modify_font(dice_face_selector_minus1,font_20);
	gtk_widget_modify_font(dice_face_selector_add10,font_20);
	gtk_widget_modify_font(dice_face_selector_minus10,font_20);
	gtk_widget_modify_font(dice_add_sum_selector,font_20);
	gtk_widget_modify_font(dice_add_sum1_selector,font_20);
	gtk_widget_modify_font(dice_setting_done_button,font_20);

	gtk_widget_modify_font(dice_keep_label,font_15);
	gtk_widget_modify_font(dice_keep_selector,font_20);
	gtk_widget_modify_font(dice_keep1_selector,font_20);
	gtk_widget_modify_font(dice_highest_label,font_15);
	gtk_widget_modify_font(dice_highest_selector,font_20);
	gtk_widget_modify_font(dice_highest1_selector,font_20);
	gtk_widget_modify_font(dice_lowest_label,font_15);
	gtk_widget_modify_font(dice_lowest_selector,font_20);
	gtk_widget_modify_font(dice_lowest1_selector,font_20);



	gtk_widget_set_size_request(dice_num_selector,80,60);
	gtk_widget_set_size_request(dice_num1_selector,80,60);
	gtk_widget_set_size_request(dice_highest_selector,80,60);
	gtk_widget_set_size_request(dice_highest1_selector,80,60);
	gtk_widget_set_size_request(dice_lowest_selector,80,60);
	gtk_widget_set_size_request(dice_lowest1_selector,80,60);
	gtk_widget_set_size_request(dice_keep_selector,80,60);
	gtk_widget_set_size_request(dice_keep1_selector,80,60);
	gtk_widget_set_size_request(dice_face_selector,80,60);
	gtk_widget_set_size_request(dice_face_selector_minus1,80,60);
	gtk_widget_set_size_request(dice_face_selector_minus10,80,60);
	gtk_widget_set_size_request(dice_face_selector_add10,80,60);
	gtk_widget_set_size_request(dice_add_sum_selector,80,60);
	gtk_widget_set_size_request(dice_add_sum1_selector,80,60);	
	gtk_widget_set_size_request(dice_setting_done_button,120,60);

	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_num_selector,420,60-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_num1_selector,510,60-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_num_label,30,75-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_face_selector,420,140-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_face_label,30,155-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_face_selector_minus1,510,140-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_face_selector_add10,600,140-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_face_selector_minus10,700,140-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_keep_selector,420,220-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_keep1_selector,510,220-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_keep_label,30,235-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_sum_add_label,30,315-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_add_sum_selector,510,300-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_add_sum1_selector,600,300-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_highest_label,30,395-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_highest_selector,510,380-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_highest1_selector,600,380-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_lowest_label,30,475-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_lowest_selector,510,460-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_lowest1_selector,600,460-20);
	gtk_fixed_put(GTK_FIXED(maingame_fixed),dice_setting_done_button,530,520);


	

	g_signal_connect(dice_num_selector,"clicked",G_CALLBACK(change_dice_num_cmd),NULL);
	g_signal_connect(dice_num1_selector,"clicked",G_CALLBACK(change_dice_num1_cmd),NULL);
	g_signal_connect(dice_keep_selector,"clicked",G_CALLBACK(change_dice_keep_cmd),NULL);
	g_signal_connect(dice_keep1_selector,"clicked",G_CALLBACK(change_dice_keep1_cmd),NULL);
	g_signal_connect(dice_highest_selector,"clicked",G_CALLBACK(change_dice_highest_cmd),NULL);
	g_signal_connect(dice_highest1_selector,"clicked",G_CALLBACK(change_dice_highest1_cmd),NULL);
	g_signal_connect(dice_lowest_selector,"clicked",G_CALLBACK(change_dice_lowest_cmd),NULL);
	g_signal_connect(dice_lowest1_selector,"clicked",G_CALLBACK(change_dice_lowest1_cmd),NULL);
	g_signal_connect(dice_face_selector,"clicked",G_CALLBACK(change_dice_face1_cmd),NULL);
	g_signal_connect(dice_face_selector_minus1,"clicked",G_CALLBACK(change_dice_facem1_cmd),NULL);
	g_signal_connect(dice_face_selector_add10,"clicked",G_CALLBACK(change_dice_face10_cmd),NULL);
	g_signal_connect(dice_face_selector_minus10,"clicked",G_CALLBACK(change_dice_facem10_cmd),NULL);
	g_signal_connect(dice_add_sum_selector,"clicked",G_CALLBACK(change_dice_add_sum_cmd),NULL);
	g_signal_connect(dice_add_sum1_selector,"clicked",G_CALLBACK(change_dice_add_sum1_cmd),NULL);
	g_signal_connect(dice_setting_done_button,"clicked",G_CALLBACK(dice_setting_done),NULL);

	gtk_container_add(GTK_CONTAINER(main_gui),maingame_fixed);
	gtk_widget_show_all(main_gui);

}

static void play_again_cmd(){

	gtk_container_remove(GTK_WINDOW(main_gui),choose_dice_fixed);

	game_start();
}

static void play_again_cmd1(){

	gtk_container_remove(GTK_WINDOW(main_gui),result_display_fixed);
	game_start();
}

static void change_dice_add_sum_cmd(){

	if(dice_lowest+dice_highest+dice_keep>=dice_num)return;
	if(dice_add_sum!=10) dice_add_sum ++;
	else dice_add_sum = -10;

	sprintf(dice_add_sum_string, "%d", dice_add_sum);
	gtk_button_set_label(GTK_BUTTON(dice_add_sum_selector), dice_add_sum_string);

}

static void change_dice_keep_cmd(){

	if(dice_lowest+dice_highest+dice_keep>=dice_num)return;
	if(dice_keep!=10) dice_keep += 1;
	else dice_keep = 0; 

	sprintf(dice_keep_string, "%d", dice_keep);
	gtk_button_set_label(GTK_BUTTON(dice_keep_selector), dice_keep_string);

}

static void change_dice_highest_cmd(){

	if(dice_lowest+dice_highest+dice_keep>=dice_num)return;
	if(dice_highest!=10) dice_highest += 1;
	else dice_highest = 0; 

	sprintf(dice_highest_string, "%d", dice_highest);
	gtk_button_set_label(GTK_BUTTON(dice_highest_selector), dice_highest_string);


}

static void change_dice_highest1_cmd(){

	if(dice_highest!=0) dice_highest -= 1;
	else return;

	sprintf(dice_highest_string, "%d", dice_highest);
	gtk_button_set_label(GTK_BUTTON(dice_highest_selector), dice_highest_string);


}

static void change_dice_lowest_cmd(){

	if(dice_lowest+dice_highest+dice_keep>=dice_num)return;
	if(dice_lowest!=10) dice_lowest += 1;
	else dice_lowest = 0; 

	sprintf(dice_lowest_string, "%d", dice_lowest);
	gtk_button_set_label(GTK_BUTTON(dice_lowest_selector), dice_lowest_string);


}

static void change_dice_lowest1_cmd(){


	if(dice_lowest!=0) dice_lowest -= 1;
	else return;

	sprintf(dice_lowest_string, "%d", dice_lowest);
	gtk_button_set_label(GTK_BUTTON(dice_lowest_selector), dice_lowest_string);


}

static void change_dice_keep1_cmd(){

	if(dice_keep!=0) dice_keep -= 1;
	else return;

	sprintf(dice_keep_string, "%d", dice_keep);
	gtk_button_set_label(GTK_BUTTON(dice_keep_selector), dice_keep_string);

}

static void change_dice_add_sum1_cmd(){

	if(dice_add_sum!=-10) dice_add_sum --;
	else dice_add_sum = 10;

	sprintf(dice_add_sum_string, "%d", dice_add_sum);
	gtk_button_set_label(GTK_BUTTON(dice_add_sum_selector), dice_add_sum_string);

}

static void change_dice_num_cmd(){


	if(dice_num!=10) dice_num ++;
	else dice_num = 0;

	sprintf(dice_num_string, "%d", dice_num);
	gtk_button_set_label(GTK_BUTTON(dice_num_selector), dice_num_string);

}

static void change_dice_num1_cmd(){

	if(dice_num!=0) dice_num --;
	else dice_num = 10;

	sprintf(dice_num_string, "%d", dice_num);
	gtk_button_set_label(GTK_BUTTON(dice_num_selector), dice_num_string);

}



static void change_dice_face_cmd(int cmd){

	dice_face += cmd;
	while(dice_face>100) dice_face -= 100;
	while(dice_face<2) dice_face += 100;
	if(dice_face>100) dice_face = 100;

	sprintf(dice_face_string, "%d", dice_face);
	gtk_button_set_label(GTK_BUTTON(dice_face_selector), dice_face_string);

}

static void change_dice_face10_cmd(){

	change_dice_face_cmd(10);

}

static void change_dice_facem10_cmd(){

	change_dice_face_cmd(-10);

}

static void change_dice_face1_cmd(){
	change_dice_face_cmd(1);
}

static void change_dice_facem1_cmd(){
	change_dice_face_cmd(-1);
}

static void setting_screen_cmd(GtkWidget * widget , gpointer data){

	

	gtk_container_remove(GTK_CONTAINER(main_gui),start_screen_box);
	setting_screen_fixed = gtk_fixed_new();

	setting_label = gtk_label_new("Coming Soon...\nBecause of Midtern,\n(Calculus and analog...)\n I cannot finish this part,\nbut I consider that I have done a lot...");
	setting_gamename_label = gtk_label_new("Dice Simulator");
	setting_back_button = gtk_button_new_with_label("Back to Main Menu");

	font_25 = pango_font_description_from_string("Times New Roman");
	pango_font_description_set_size(font_25,25*PANGO_SCALE);
	gtk_widget_modify_font(setting_label,font_25);
	gtk_widget_modify_font(setting_gamename_label,font_40);
	gtk_widget_modify_font(setting_back_button,font_20);

	gtk_widget_set_size_request(setting_back_button,150,60);

	gtk_fixed_put(GTK_FIXED(setting_screen_fixed),setting_label,70,250);
	gtk_fixed_put(GTK_FIXED(setting_screen_fixed),setting_gamename_label,200,90);
	gtk_fixed_put(GTK_FIXED(setting_screen_fixed),setting_back_button,500,530);

	g_signal_connect(setting_back_button,"clicked",G_CALLBACK(back_to_main_menu_cmd),NULL);

	gtk_container_add(GTK_CONTAINER(main_gui),setting_screen_fixed);

	gtk_widget_show_all(main_gui);


}

static void back_to_main_menu_cmd(GtkWidget * widget , gpointer data){

	gtk_container_remove(GTK_CONTAINER(main_gui),setting_screen_fixed);

	start_screen_box = gtk_fixed_new();

	start_message_label = gtk_label_new("Dice Simulator");
	author_label = gtk_label_new("Author : 41247001S");
	//gtk_label_set_text(GTK_LABEL(start_message_label),"Messages");

	start_game_button = gtk_button_new_with_label("Start the game !");
	start_screen_setting_button = gtk_button_new_with_label("Setting");
	exit_game_button = gtk_button_new_with_label("Exit!");
	


	gtk_widget_modify_font(start_message_label,font_40);


	gtk_widget_modify_font(start_game_button,font_20);
	gtk_widget_modify_font(exit_game_button,font_20);
	gtk_widget_modify_font(start_screen_setting_button,font_20);
	gtk_widget_modify_font(author_label,font_20);

	gtk_widget_set_size_request(start_game_button,300,80);
	gtk_widget_set_size_request(exit_game_button,300,80);
	gtk_widget_set_size_request(start_screen_setting_button,300,80);

	gtk_container_add(GTK_CONTAINER(main_gui),start_screen_box);

	gtk_fixed_put(GTK_FIXED(start_screen_box),start_message_label,200,90);
	gtk_fixed_put(GTK_FIXED(start_screen_box),author_label,480,530);
	gtk_fixed_put(GTK_FIXED(start_screen_box),start_game_button,250,210);
	gtk_fixed_put(GTK_FIXED(start_screen_box),exit_game_button,250,410);
	gtk_fixed_put(GTK_FIXED(start_screen_box),start_screen_setting_button,250,310);

	g_signal_connect(main_gui,"delete-event",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(exit_game_button,"clicked",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(start_game_button,"clicked",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(start_screen_setting_button,"clicked",G_CALLBACK(setting_screen_cmd),NULL);

	gtk_container_add(GTK_CONTAINER(main_gui),start_screen_box);
	gtk_widget_show_all(main_gui);


}



static void start_game_cmd(GtkWidget * widget , gpointer data){

	gtk_container_remove(GTK_CONTAINER(main_gui),start_screen_box);

	story_message_label =  gtk_label_new("Once upon a time........");

	story_screen_fixed = gtk_fixed_new();
	

	gtk_widget_modify_font(story_message_label,font_40);	

	story_skip_button = gtk_button_new_with_label(story_skip_words);
	story_next_button = gtk_button_new_with_label("Next");

	font_10 = pango_font_description_from_string("Times New Roman");
	pango_font_description_set_size(font_10,10*PANGO_SCALE);



	gtk_widget_modify_font(story_skip_button,font_10);
	gtk_widget_modify_font(story_next_button,font_20);


	gtk_widget_set_size_request(story_skip_button,100,40);
	gtk_widget_set_size_request(story_next_button,150,60);

	gtk_fixed_put(GTK_FIXED(story_screen_fixed),story_message_label,100,250);
	gtk_fixed_put(GTK_FIXED(story_screen_fixed),story_next_button,575,500);
	gtk_fixed_put(GTK_FIXED(story_screen_fixed),story_skip_button,25,25);

	g_signal_connect(story_skip_button,"clicked",G_CALLBACK(story_end_cmd),NULL);
	g_signal_connect(story_next_button,"clicked",G_CALLBACK(story_page_changed),NULL);


	gtk_container_add(GTK_CONTAINER(main_gui),story_screen_fixed);
	gtk_widget_show_all(main_gui);

	

}


static void story_page_changed(GtkWidget *widget , gpointer data){

	if(story_page == 0){
		gtk_label_set_text(GTK_LABEL(story_message_label),"Professor Chi Decided to play Dice game");
		story_page = 1;
		font_23 = pango_font_description_from_string("Times New Roman");
		pango_font_description_set_size(font_23,23*PANGO_SCALE);
		gtk_widget_modify_font(story_message_label,font_23);
		gtk_fixed_move(GTK_FIXED(story_screen_fixed),story_message_label,80,250);

	}
	else if(story_page==1){
		gtk_label_set_text(GTK_LABEL(story_message_label),"Therefore, he force his students to write a\n Dice game as a homework");
		story_page = 2;

		gtk_fixed_move(GTK_FIXED(story_screen_fixed),story_message_label,80,250);
	}
	else if(story_page==2){
		gtk_label_set_text(GTK_LABEL(story_message_label),"However, a Dice game without GUI is boring...");
		story_page = 3;

		gtk_fixed_move(GTK_FIXED(story_screen_fixed),story_message_label,40,250);
	}
	else if(story_page == 3){
		gtk_container_remove(GTK_CONTAINER(main_gui),story_screen_fixed);
		game_start();

	}

}


static void story_end_cmd(GtkWidget *widget , gpointer data){

	if(story_skip_times==0){
		story_skip_times += 1;
		story_skip_words = "Continue?";
		gtk_button_set_label(GTK_BUTTON(story_skip_button), story_skip_words);
	}
	else{
		gtk_container_remove(GTK_CONTAINER(main_gui),story_screen_fixed);
		game_start();
	}




}