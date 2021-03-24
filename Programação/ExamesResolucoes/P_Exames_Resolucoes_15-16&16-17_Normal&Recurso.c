
/*
__________________________________________________
Resoluções completas dos exames:
	Exame Normal 	15/16
	Exame Recurso 	15/16
	Exame Normal 	16/17
	Exame Recurso 	16/17
__________________________________________________
	Done by: Ricardo Calvão
__________________________________________________
Obs: Só fiz error handling para as alíneas
	que pede explicitamente para fazer,
	de forma a simplificar as resoluções.
__________________________________________________
*/

// Exame Normal 15/16

// Ex_1
void ex_1(char * fich_nome) {

	FILE * fp;
	int ch;
	bool inicio_palavra;

	fp = fopen(fich_nome, "rt");

	inicio_palavra = true;
	while ((ch = fgetc(fp)) != EOF) {

		if (isalpha(ch) && inicio_palavra) {
			ch = toupper(ch);
			inicio_palavra = false;
		}

		if (isspace(ch)) {
			inicio_palavra = true;
		}

		putchar(ch);
	}

	fclose(fp);
}

// Ex_2
struct data {
	int dia, mes, ano;
};

struct pessoa {
	char nome[50];
	char telefone[20];
	struct data data_nasc;
};

struct xpessoa {
	char nome[50];
	char telefone[20];
	struct data data_nasc;
	char email[50];
};

#define TAM 256

void ex_2(char * fich_nome) {

	FILE * fp_ori;
	FILE * fp_final;
	struct pessoa men;
	struct xpessoa xmen;
	char fich_novo_nome[TAM];

	fp_ori = fopen(fich_nome, "rb");
	fp_final = fopen("catsanddogs", "wb");

	while (fread(&men, sizeof(struct pessoa), 1, fp_ori) == 1) {

		strcpy(xmen.nome, men.nome);
		strcpy(xmen.telefone, men.telefone);
		xmen.data_nasc = men.data_nasc;
		strcpy(xmen.email, "nao definido");

		fwrite(&xmen, sizeof(struct xpessoa), 1, fp_final);
	}

	fclose(fp_ori);
	fclose(fp_final);

	strcpy(fich_novo_nome, fich_nome);
	strcat(fich_novo_nome, ".bak");
	rename(fich_nome, fich_novo_nome);
	rename("catsanddogs", fich_nome);
}

// Ex_3

typedef struct res no, *pno;
typedef struct d eq, *pequipa;
struct res {
	int id_eq[2], golos[2];
	pequipa pont[2];
	pno prox;
};
struct d {
	char nome[50];
	int id;
	int v, e, d;
};

// Ex_3_a
void ex_3_a(no * lista_res, eq * vec_equipas, int n_equipas) {

	int i;
	no * no;

	no = lista_res;
	while (no != NULL) {

		for (i = 0; i < n_equipas; i++) {
			if (no->id_eq[0] == vec_equipas[i].id) {
				no->pont[0] = &vec_equipas[i];
			}
			else {
				if (no->id_eq[1] == vec_equipas[i].id) {
					no->pont[1] = &vec_equipas[i];
				}
			}
		}

		if (no->golos[0] == no->golos[1]) {
			(no->pont[0]->e)++;
			(no->pont[1]->e)++;
		}
		else {
			if (no->golos[0] > no->golos[1]) {
				(no->pont[0]->v)++;
				(no->pont[1]->d)++;
			}
			else {
				(no->pont[0]->d)++;
				(no->pont[1]->v)++;
			}
		}

		no = no->prox;
	}
}

// Ex_3_b
pequipa atualiza(int id, pequipa v, int * total, pno * lista) {

	int i, j;
	no ** no_aux;
	no * no;
	eq * v_aux;
	bool found;

	no_aux = lista;
	while (*no_aux != NULL) {

		found = false;
		no = *no_aux;
		if (no->id_eq[0] == id) {
			if (no->golos[0] == no->golos[1]) {
				(no->pont[1]->e)--;
			}
			else {
				if (no->golos[0] > no->golos[1]) {
					(no->pont[1]->d)--;
				}
				else {
					(no->pont[1]->v)--;
				}
			}
			found = true;
		}
		if (no->id_eq[1] == id) {
			if (no->golos[0] == no->golos[1]) {
				(no->pont[0]->e)--;
			}
			else {
				if (no->golos[0] > no->golos[1]) {
					(no->pont[0]->v)--;
				}
				else {
					(no->pont[0]->d)--;
				}
			}
			found = true;
		}

		if (found) {
			no = *no_aux;
			no_aux = &(*no_aux)->prox;
			free(no);
		}
		
		no_aux = &(*no_aux)->prox;
	}

	v_aux = malloc(sizeof(eq) * (*total - 1));

	found = false;
	for (i = 0, j = 0; i < *total && j < *total - 1; i++) {

		if (v[i].id == id) {
			found = true;
			continue;
		}

		v_aux[j] = v[i];
		j++;
	}

	if (found) {
		(*total)--;
		return v_aux;
	}
	else {
		free(v_aux);
		return v;
	}
}


// Ex_3
typedef struct res no, *pno;
typedef struct pessoa jog, *pjog;

struct data { int dia, mes, ano; };

struct res {
	int id_eq[2];
	int golos[2];
	int *m;
	struct data d;
	pno prox;
};

struct pessoa {
	char nome[50];
	int id;
	int idade;
};

// Ex_3_a
struct jogador_golos {
	int id_jogador;
	int n_golos_total;
	jog * p_jog;
};
typedef struct jogador_golos jogador_golos;

void ex_3_a(no * lista, jog * vec_jogadores, int n_jogadores) {

	int i, j;
	jogador_golos * vec_golos;
	int n_marcadores;
	bool contabilizado;
	jogador_golos melhor_marcador;

	vec_golos = calloc(n_jogadores, sizeof(jogador_golos));

	n_marcadores = 0;
	while (lista != NULL) {

		for (i = 0; i < lista->golos[0] + lista->golos[1]; i++) {

			contabilizado = false;
			for (j = 0; j < n_marcadores; j++) {
				if (lista->m[i] == vec_golos[j].id_jogador) {
					(vec_golos[j].n_golos_total)++;
					contabilizado = true;
					break;
				}
			}
			if (contabilizado == false) {
				vec_golos[n_marcadores].id_jogador = lista->m[i];
				(vec_golos[n_marcadores].n_golos_total)++;
				n_marcadores++;
			}

		}
		lista = lista->prox;
	}

	for (i = 0; i < n_marcadores; j++) {
		for (j = 0; j < n_jogadores; j++) {
			if (vec_golos[i].id_jogador == vec_jogadores[j].id) {
				vec_golos[i].p_jog = &vec_jogadores[j];
			}
		}
	}

	melhor_marcador.n_golos_total = 0;
	for (i = 0; i < n_marcadores; i++) {

		if (vec_golos[i].n_golos_total == melhor_marcador.n_golos_total) {
			if (vec_golos[i].p_jog->idade < melhor_marcador.p_jog->idade) {
				melhor_marcador = vec_golos[i];
				continue;
			}
		}

		if (vec_golos[i].n_golos_total > melhor_marcador.n_golos_total) {
			melhor_marcador = vec_golos[i];
		}
	}

	printf("ID: %d\nNome: %s\n",
		melhor_marcador.id_jogador,
		melhor_marcador.p_jog->nome);
}

// Ex_3_b
pjog atualiza(char * txt, pjog v, int * total, pno * lista) {

	FILE * fp;
	no jogo;
	jog jogador;
	int i, j;
	jog * vec_jogadores_aux;
	bool found;
	no * novo_jogo;
	no * no_aux;

	fp = fopen(txt, "rt");

	fscanf(fp, " %d %d %d %d %d %d %d",
		&jogo.id_eq[0],
		&jogo.id_eq[1],
		&jogo.d.dia,
		&jogo.d.mes,
		&jogo.d.ano,
		&jogo.golos[0],
		&jogo.golos[1]);

	jogo.m = malloc(sizeof(int) * (jogo.golos[0] + jogo.golos[1]));

	v = NULL;
	for (i = 0; i < jogo.golos[0] + jogo.golos[1]; i++) {

		fscanf(fp, " %d %d %[^\n]",
			&jogador.id,
			&jogador.idade,
			jogador.nome);

		jogo.m[i] = jogador.id;

		found = false;
		for (j = 0; j < *total; j++) {
			if (v[j].id == jogador.id) {
				found = true;
				break;
			}
		}
		if (found == true) {
			continue;
		}

		vec_jogadores_aux = realloc(v, sizeof(jog) * (*total + 1));
		vec_jogadores_aux[*total] = jogador;
		(*total)++;
		v = vec_jogadores_aux;
	}

	novo_jogo = malloc(sizeof(no));
	*novo_jogo = jogo;

	if (*lista == NULL ||
		(*lista)->d.dia > jogo.d.dia &&
		(*lista)->d.mes == jogo.d.mes &&
		(*lista)->d.ano == jogo.d.ano ||
		(*lista)->d.mes > jogo.d.mes &&
		(*lista)->d.ano == jogo.d.ano ||
		(*lista)->d.ano > jogo.d.ano) {

		novo_jogo->prox = *lista;
		*lista = novo_jogo;
	}
	else {

		no_aux = *lista;
		while (no_aux->prox != NULL &&
			(no_aux->prox->d.dia < jogo.d.dia &&
			no_aux->prox->d.mes == jogo.d.mes &&
			no_aux->prox->d.ano == jogo.d.ano ||
			no_aux->prox->d.mes < jogo.d.mes &&
			no_aux->prox->d.ano == jogo.d.ano ||
			no_aux->prox->d.ano < jogo.d.ano)) {

			no_aux = no_aux->prox;
		}

		novo_jogo->prox = no_aux->prox;
		no_aux->prox = novo_jogo;
	}

	fclose(fp);
	return v;
}

// Exame Normal 16/17

// Ex_1
typedef struct sessao sessao;
typedef struct bilhete bilhete;

struct sessao {
	int sala;
	struct {
		int h;
		int m;
	} hora;
};

struct bilhete {
	struct sessao s;
	char id[10];
	int lugar;
};

// Ex_1_a
int ex_1_a(char * fich_bin_nome, char * fich_final_nome, struct sessao sessao) {

	FILE * fp_ori;
	FILE * fp_final;
	long file_size;
	int n_bilhetes;
	struct bilhete * vec_bilhetes;
	int i;
	int n_clientes_escritos;

	fp_ori = fopen(fich_bin_nome, "rb");
	if (fp_ori == NULL) {
		return -1;
	}
	
	if (fseek(fp_ori, 0, SEEK_END) != 0) {
		fclose(fp_ori);
		return -1;
	}
	file_size = ftell(fp_ori);
	if (file_size == -1L) {
		fclose(fp_ori);
		return -1;
	}
	if (fseek(fp_ori, 0, SEEK_SET) != 0) {
		fclose(fp_ori);
		return -1;
	}

	if(file_size % sizeof(struct bilhete) != 0) {
		fclose(fp_ori);
		return -1;
	}
	n_bilhetes = (int)(file_size / sizeof(struct bilhete));

	vec_bilhetes = malloc(sizeof(struct bilhete) * n_bilhetes);
	if (vec_bilhetes == NULL) {
		fclose(fp_ori);
		return -1;
	}

	if (fread(vec_bilhetes, sizeof(struct bilhete), n_bilhetes, fp_ori) != n_bilhetes) {
		free(vec_bilhetes);
		fclose(fp_ori);
		return -1;
	}

	fclose(fp_ori);

	fp_final = fopen(fich_final_nome, "wt");
	if (fp_final == NULL) {
		free(vec_bilhetes);
		return -1;
	}

	n_clientes_escritos = 0;
	for (i = 0; i < n_bilhetes; i++) {
		if (vec_bilhetes[i].s.sala == sessao.sala &&
			vec_bilhetes[i].s.hora.m == sessao.hora.m &&
			vec_bilhetes[i].s.hora.h == sessao.hora.h) {

			if (fprintf(fp_final, "%s\n",
				vec_bilhetes[i].id) != strlen(vec_bilhetes[i].id) + 1) {

				free(vec_bilhetes);
				fclose(fp_final);
				return -1;
			}

			n_clientes_escritos++;
		}
	}

	free(vec_bilhetes);
	fclose(fp_final);
	return n_clientes_escritos;
}

// Ex_1_b
struct sessao * criaVetor(char * nome, int * total) {

	FILE * fp_ori;
	long file_size;
	int n_bilhetes;
	struct bilhete * vec_bilhetes;
	struct sessao * vec_sessoes;
	struct sessao * vec_sessoes_aux;
	int i, j;
	bool found;

	fp_ori = fopen(nome, "rb");
	if (fp_ori == NULL) {
		return NULL;
	}

	if (fseek(fp_ori, 0, SEEK_END) != 0) {
		fclose(fp_ori);
		return NULL;
	}
	file_size = ftell(fp_ori);
	if (file_size == -1L) {
		fclose(fp_ori);
		return NULL;
	}
	if (fseek(fp_ori, 0, SEEK_SET) != 0) {
		fclose(fp_ori);
		return NULL;
	}

	n_bilhetes = (int)(file_size / sizeof(struct bilhete));

	vec_bilhetes = malloc(sizeof(struct bilhete) * n_bilhetes);
	if (vec_bilhetes == NULL) {
		fclose(fp_ori);
		return NULL;
	}

	if (fread(vec_bilhetes, sizeof(struct bilhete), n_bilhetes, fp_ori) != n_bilhetes) {
		free(vec_bilhetes);
		fclose(fp_ori);
		return NULL;
	}

	fclose(fp_ori);

	*total = 0;
	vec_sessoes = NULL;
	for (i = 0; i < n_bilhetes; i++) {

		found = false;
		for (j = 0; j < *total; j++) {
			if (vec_bilhetes[i].s.sala == vec_sessoes[j].sala &&
				vec_bilhetes[i].s.hora.m == vec_sessoes[j].hora.m &&
				vec_bilhetes[i].s.hora.h == vec_sessoes[j].hora.h) {

				found = true;
				break;
			}
		}

		if (found) {
			continue;
		}

		vec_sessoes_aux = realloc(vec_sessoes, sizeof(struct sessao) * (*total + 1));
		if (vec_sessoes_aux == NULL) {
			free(vec_sessoes);
			return NULL;
		}
		vec_sessoes_aux[*total] = vec_bilhetes[i].s;
		(*total)++;
		vec_sessoes = vec_sessoes_aux;
	}

	return vec_sessoes;
}

// Ex_1_c
int ex_1_c(char * fich_bin_nome) {

	FILE * fp_ori;
	long file_size;
	int n_bilhetes;
	int n_sessoes;
	struct bilhete * vec_bilhetes;
	struct sessao * vec_sessoes;
	int i, j;
	int n_assistencias;
	int n_assistencias_max;

	fp_ori = fopen(fich_bin_nome, "rb");
	
	fseek(fp_ori, 0, SEEK_END);
	file_size = ftell(fp_ori);
	fseek(fp_ori, 0, SEEK_SET);

	n_bilhetes = (int)(file_size / sizeof(struct bilhete));

	vec_bilhetes = malloc(sizeof(struct bilhete) * n_bilhetes);
	
	fread(vec_bilhetes, sizeof(struct bilhete), n_bilhetes, fp_ori);

	fclose(fp_ori);

	vec_sessoes = criaVetor(fich_bin_nome, &n_sessoes);

	n_assistencias_max = 0;
	for (i = 0; i < n_sessoes; i++) {
		n_assistencias = 0;
		for (j = 0; j < n_bilhetes; j++) {
			if (vec_sessoes[i].sala == vec_bilhetes[j].s.sala &&
				vec_sessoes[i].hora.m == vec_bilhetes[j].s.hora.m &&
				vec_sessoes[i].hora.h == vec_bilhetes[j].s.hora.h) {

				n_assistencias++;
			}
		}
		if (n_assistencias > n_assistencias_max) {
			n_assistencias_max = n_assistencias;
		}
	}

	free(vec_bilhetes);
	free(vec_sessoes);
	return n_assistencias_max;
}

// Ex_2
///*
typedef struct produto Prod, *pProd;
typedef struct entrada Ent, *pEnt;
typedef struct existencia Exist, *pExist;

struct produto {
	int id;
	char designacao[100];
	char familia[30];
};

struct entrada {
	int qt;
	float preco_compra;
	pEnt prox;
};

struct existencia {
	pProd p;
	pEnt entradas;
	pExist prox;
};

// Ex_2_a
float ex_2_a(Exist * lista, int id_produto) {

	float res;
	int quantidade_total;
	Ent * entrada_actual;

	while (lista != NULL && lista->p->id != id_produto) {
		lista = lista->prox;
	}

	if (lista == NULL) {
		return -1;
	}

	res = 0;
	quantidade_total = 0;
	entrada_actual = lista->entradas;
	while (entrada_actual != NULL) {
		res += (entrada_actual->qt * entrada_actual->preco_compra);
		quantidade_total += entrada_actual->qt;

		entrada_actual = entrada_actual->prox;
	}

	return res / (float)quantidade_total;
}

// Ex_2_b
Exist * ex_2_b(Exist * lista, int id_produto, int quantidade) {

	Exist * exist;
	Exist * exist_anterior;
	Ent * entrada_actual;
	
	exist = exist_anterior = lista;
	while (exist != NULL && exist->p->id != id_produto) {
		exist_anterior = exist;
		exist = exist->prox;
	}

	entrada_actual = exist->entradas;
	while (entrada_actual != NULL && quantidade > 0) {
		
		if (entrada_actual->qt > quantidade) {
			entrada_actual->qt -= quantidade;
			quantidade = 0;
			break;
		}
	
		if (entrada_actual->qt <= quantidade) {

			quantidade -= entrada_actual->qt;

			exist->entradas = entrada_actual->prox;
			free(entrada_actual);
			entrada_actual = exist->entradas;
		}
	}

	if (exist->entradas == NULL) {
		if (exist == lista) {
			lista = exist->prox;
			free(exist);
		}
		else {
			exist_anterior->prox = exist->prox;
			free(exist);
		}
	}

	return lista;
}

// Exame Recurso 16/17

// Ex_1
#define TAM 1024

// Ex_1_a
void ex_1_a(char * fich_nome, char * nome_musica) {

	FILE * fp_ori;
	FILE * fp_final;
	char linha[TAM];
	char nome_lido[TAM];
	bool found;

	fp_ori = fopen(fich_nome, "rt");
	fp_final = fopen("catsanddogs", "wt");

	found = false;
	while (fgets(linha, TAM, fp_ori) != NULL) {

		sscanf(linha, "%[^;]", nome_lido);
		if (!strcmp(nome_lido, nome_musica)) {
			found = true;
			continue;
		}

		fputs(linha, fp_final);
	}

	fclose(fp_ori);
	fclose(fp_final);

	if (found) {
		remove(fich_nome);
		rename("catsanddogs", fich_nome);
	}
	else {
		remove("catsanddogs");
	}
}

typedef struct duracaoDados {
	int horas, minutos;
} duracao;
typedef struct musicaDados {
	char nome[200], autor[200];
	duracao d;
	int ano;
} musica;

// Ex_1_b
musica * funcB(char * fichTXT, char * fichBIN, int * total) {

	FILE * fp_txt;
	FILE * fp_bin;
	musica * vec_full;
	musica * vec_return;
	musica * p_aux;
	char linha[TAM];
	musica m_aux;
	int total_musicas;


	*total = 0;

	fp_txt = fopen(fichTXT, "rt");
	if (fp_txt == NULL) {
		return NULL;
	}

	vec_full = NULL;
	vec_return = NULL;
	total_musicas = 0;
	while (fgets(linha, TAM, fp_txt) != NULL) {

		if (sscanf(linha,
			" %199[^;]; %199[^;]; %d:%d; %d",
			m_aux.nome,
			m_aux.autor,
			&m_aux.d.horas,
			&m_aux.d.minutos,
			&m_aux.ano) != 5) {

			fclose(fp_txt);
			free(vec_full);
			free(vec_return);
			return NULL;
		}

		p_aux = realloc(vec_full, sizeof(musica) * (total_musicas + 1));
		if (p_aux == NULL) {
			fclose(fp_txt);
			free(vec_full);
			free(vec_return);
			return NULL;
		}
		vec_full[total_musicas] = m_aux;
		total_musicas++;

		if (m_aux.ano <= 2000) {
			continue;
		}

		p_aux = realloc(vec_return, sizeof(musica) * (*total + 1));
		if (p_aux == NULL) {
			fclose(fp_txt);
			free(vec_full);
			free(vec_return);
			return NULL;
		}
		vec_return[*total] = m_aux;
		(*total)++;
	}

	fclose(fp_txt);

	fp_bin = fopen(fichBIN, "wb");
	if (fp_bin == NULL) {
		free(vec_full);
		free(vec_return);
		return NULL;
	}

	if (fwrite(vec_full, sizeof(musica), total_musicas, fp_bin) != total_musicas) {
		free(vec_full);
		free(vec_return);
		return NULL;
	}

	fclose(fp_bin);
	free(vec_full);

	return vec_return;
}

// Ex_1_c
void ex_1_c(char * fich_nome) {

	FILE * fp;
	long file_size;
	int n_musicas;
	musica * vec_musicas;
	int i, j;
	bool you_are_the_only_one;

	fp = fopen(fich_nome, "rb");

	fseek(fp, 0, SEEK_END);
	file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	n_musicas = (int)(file_size / sizeof(musica));

	vec_musicas = malloc(sizeof(musica) * n_musicas);
	fread(vec_musicas, sizeof(musica), n_musicas, fp);

	fclose(fp);

	for (i = 0; i < n_musicas; i++) {
		you_are_the_only_one = true; // :')
		for (j = 0; j < n_musicas; j++) {

			if (i == j) continue;

			if (!strcmp(vec_musicas[i].autor, vec_musicas[j].autor)) {
				you_are_the_only_one = false;
				break;
			}
		}

		if (you_are_the_only_one) {
			puts(vec_musicas[i].autor);
		}
	}
}

// Ex_2
typedef struct infoTurma turma, *pturma;
typedef struct aluno al, *pal;
typedef struct disciplina no, *pno;

struct infoTurma {
	char id[20];
	pal vAlunos;
	int nAlunos;
};
struct aluno {
	char nome[100];
	char id[20];
	pno vp[3];
};
struct disciplina {
	char nome[100];
	int conta;
	pno prox;
};

// Ex_2_a
void ex_2_a(turma * vec_turma, int n_turmas, no * list_disciplinas) {

	int i, j, k;

	for (i = 0; i < n_turmas; i++) {
		for (j = 0; j < vec_turma[i].nAlunos; j++) {
			for (k = 0; k < 3; k++) {

				if (vec_turma[i].vAlunos[j].vp[k] == NULL) break;

				(vec_turma[i].vAlunos[j].vp[k]->conta)++;
			}
		}
	}
}

// Ex_2_b
no * ex_2_b(char * id_eliminar, turma * vec_turma, int n_turmas, no * list_disciplinas) {

	int i, j, k, l;
	al * vec_alunos_aux;
	no * no_aux;
	no * no_anterior;

	for (i = 0; i < n_turmas; i++) {
		for (j = 0; j < vec_turma[i].nAlunos; j++) {

			if (!strcmp(vec_turma[i].vAlunos[j].id, id_eliminar)) {
				break;
			}
		}
	}

	for (k = 0; k < 3; k++) {

		if (vec_turma[i].vAlunos[j].vp[k] == NULL) break;

		(vec_turma[i].vAlunos[j].vp[k]->conta)--;
		if (vec_turma[i].vAlunos[j].vp[k]->conta > 0) continue;

		if (vec_turma[i].vAlunos[j].vp[k] == list_disciplinas) {
			list_disciplinas = vec_turma[i].vAlunos[j].vp[k]->prox;
			free(vec_turma[i].vAlunos[j].vp[k]);
		}
		else {
			no_aux = list_disciplinas;
			while (no_aux != vec_turma[i].vAlunos[j].vp[k]) {

				no_anterior = no_aux;
				no_aux = no_aux->prox;
			}
			no_anterior->prox = no_aux->prox;
			free(no_aux);
		}
	}

	vec_alunos_aux = malloc(sizeof(al) * (vec_turma[i].nAlunos - 1));

	for (k = 0, l = 0; k < vec_turma[i].nAlunos; k++) {

		if (k == j) continue;

		vec_alunos_aux[l] = vec_turma[i].vAlunos[k];
		l++;
	}

	free(vec_turma[i].vAlunos);
	vec_turma[i].vAlunos = vec_alunos_aux;

	return list_disciplinas;
}
