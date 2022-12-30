#include "server.h"
#define MAX_MESSAGE_SIZE 1024
#define ADDR "127.0.0.1"
#define PORT "8000"
// SHIPS
#define CARRIER 5
#define BATTLESHIP 4
#define CRUISER_1 3
#define CRUISER_2 3
#define SUBMARINE 3
#define DESTROYER 2

char *board[10][10] = {{"", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"},
                       {"A", "", "", "", "", "", "", "", "", ""},
                       {"B", "", "", "", "", "", "", "", "", ""},
                       {"C", "", "", "", "", "", "", "", "", ""},
                       {"D", "", "", "", "", "", "", "", "", ""},
                       {"E", "", "", "", "", "", "", "", "", ""},
                       {"F", "", "", "", "", "", "", "", "", ""},
                       {"G", "", "", "", "", "", "", "", "", ""},
                       {"H", "", "", "", "", "", "", "", "", ""},
                       {"I", "", "", "", "", "", "", "", "", ""},
                       {"J", "", "", "", "", "", "", "", "", ""}};

void printBoard()
{
    
    for (int l = 0; l < 10; l++)
    {
        for (int c = 0; c < 10; c++)
        {
            if (c == 9)
            {
                printf("%s", (board[l][c] != "") ? board[l][c] : " ");
            }
            else
            {
                printf("%s|", (board[l][c] != "") ? board[l][c] : " ");
            }
        }
        printf("\n- - - - - - - - - -\n");
    }
}

// char *read_file(char *filename)
// {
//     // On ouvre le fichier en lecture seule
//     int fd = open(filename, O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Erreur lors de l'ouverture du fichier");
//         exit(EXIT_FAILURE);
//     }

//     // On récupère la taille du fichier
//     long int file_size = lseek(fd, 0, SEEK_END);

//     // On se replace au début du fichier
//     lseek(fd, 0, SEEK_SET);

//     // On alloue de la mémoire pour contenir le fichier
//     char *file_content = malloc(file_size + 1);
//     if (file_content == NULL)
//     {
//         perror("Erreur lors de l'allocation de mémoire pour le fichier");
//         exit(EXIT_FAILURE);
//     }

//     // On lit le contenu du fichier
//     int bytes_read = read(fd, file_content, file_size);
//     if (bytes_read == -1)
//     {
//         perror("Erreur lors de la lecture du fichier");
//         exit(EXIT_FAILURE);
//     }

//     // On ajoute un caractère de fin de chaîne à la fin du fichier
//     // pour pouvoir le traiter comme une chaîne de caractères
//     file_content[file_size] = '\0';

//     // On ferme le fichier
//     close(fd);

//     // On renvoie le contenu du fichier
//     return file_content;
// }

// void server()
// {
//     // On prépare la structure addrinfo avec les informations
//     // nécessaires pour créer le socket
//     struct addrinfo hints;
//     memset(&hints, 0, sizeof(hints));
//     hints.ai_family = AF_INET;
//     hints.ai_socktype = SOCK_STREAM;
//     hints.ai_flags = AI_PASSIVE;

//     // On récupère la liste des informations de connexion
//     // en utilisant getaddrinfo
//     struct addrinfo *server_info;
//     int status = getaddrinfo(NULL, PORT, &hints, &server_info);
//     if (status != 0)
//     {
//         fprintf(stderr, "Erreur lors de l'appel à getaddrinfo : %s\n", gai_strerror(status));
//         exit(EXIT_FAILURE);
//     }

//     // On crée le socket en utilisant les informations de server_info
//     int sock = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
//     if (sock == -1)
//     {
//         perror("Erreur lors de la création du socket");
//         exit(EXIT_FAILURE);
//     }

//     // On lie le socket à l'adresse et au port spécifiés
//     status = bind(sock, server_info->ai_addr, server_info->ai_addrlen);
//     if (status == -1)
//     {
//         perror("Erreur lors du bind du socket");
//         exit(EXIT_FAILURE);
//     }

//     // On n'a plus besoin des informations de server_info, on peut donc les libérer
//     freeaddrinfo(server_info);

//     // On met le socket en écoute, prêt à accepter des connexions entrantes
//     if (listen(sock, 20) == -1)
//     {
//         perror("Erreur lors de l'appel à listen");
//         exit(EXIT_FAILURE);
//     }

//     printf("Le serveur est en écoute sur le port %s\n", PORT);

//     // On accepte les connexions entrantes indéfiniment
//     while (1)
//     {
//         // On accepte une connexion entrante
//         struct sockaddr_storage client;
//         socklen_t client_size = sizeof(client);
//         int connection = accept(sock, (struct sockaddr *)&client, &client_size);
//         if (connection == -1)
//         {
//             perror("Erreur lors de l'appel à accept");
//             exit(EXIT_FAILURE);
//         }

//         // On lit le message envoyé par le client
//         char message[MAX_MESSAGE_SIZE];
//         int bytes_read = recv(connection, message, MAX_MESSAGE_SIZE - 1, 0);
//         if (bytes_read == -1)
//         {
//             perror("Erreur lors de la réception du message du client");
//             exit(EXIT_FAILURE);
//         }

//         // On ajoute un caractère de fin de chaîne à la fin du message
//         // pour pouvoir l'afficher correctement avec printf
//         message[bytes_read] = '\0';
//         printf("Message reçu de %s : %s", inet_ntop(server_info->ai_addr, &client), message);

//         // On envoie une réponse au client
//         // const char *response = "Bienvenue sur le serveur TCP !\n";
//         // send(connection, response, strlen(response), 0);

//         // On lit le contenu du fichier index.html
//         char *file_content = read_file("index.html");

//         // On envoie le contenu du fichier au client
//         send(connection, file_content, strlen(file_content), 0);

//         // On libère la mémoire allouée pour le contenu du fichier
//         free(file_content);

//         // On ferme la connexion
//         close(connection);
//     }

//     // On ferme le socket
//     close(sock);
// }
