#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char* note_content;
}note;
typedef struct {
	note a[50];
	int count_note;
} List_note;
void print_note(List_note l) {
	printf("There are things to do:\n");
	for (int i = 0 ; i < l.count_note ; i++) {
		printf("%d. %s\n",i+1, l.a[i].note_content);
	}
	printf("            -----------------\n");
}
void reset_note(List_note* l) {
	l->count_note = 0;
	printf("Note reseted!\n");
}
void add_note(List_note* l) {
	printf("Type the content of note:\n");
	char s[100] ;
	fgets(s, 100, stdin);
	s[strcspn(s,"\n")] ='\0';
	system("cls");
	l->a[l->count_note].note_content = strdup(s);
	l->count_note++;
	printf("Note added!\n");
}
void del_note(List_note* l) {
	l->count_note--;
	printf("Note deleted!\n");	
}
void print_selection() {
	printf("1. Reset\n2. Add new note\n3. Delete last note\n4. Print note to the screen\n5. Exit\nYou choose: ");
}
void run_program() {
	int n;
	List_note l;
	print_selection();
	scanf("%d",&n);
	while (n != 5 && n <=5 && n >=1) {
		if (n == 1) {
			system("cls");
			reset_note(&l);
		}
		if (n == 2) {
			system("cls");
			int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
			add_note(&l);
		}
		if (n == 3) {
			system("cls");
			del_note(&l);
		}
		if (n == 4) {
			system("cls");
			print_note(l);
		}
		printf("What you want to do next?\n");
		print_selection();
		scanf(" %d", &n);
	}
}
int main() {
	run_program();
	return 0;
}
