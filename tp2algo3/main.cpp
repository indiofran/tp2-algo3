#include <iostream>
#include "segmentation/segmentation.h"
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstring>
#include <random>

void guide();
vector<vector<int>> read_image(string& path);
vector<vector<int>> read_stdio();
void save_image(vector<vector<int>> image, vector<int> segments, int k);
void write_stdio(vector<vector<int>> segmented_image);
void segment_image_by_path(char* argv[]);
void segment_image_by_stdio(char* argv[]);

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        segment_image_by_stdio(argv);
    }
    else if (argc == 2 && strncmp(argv[1], "-h", 2) == 0)
    {
        guide();
    }
    else if (argc == 5)
    {
        segment_image_by_path(argv);
    }
    else
    {
        guide();
    }

    return 0;
}

vector<vector<int>> read_image(string& path)
{
    /*
       Formato PGM:
        NÚMERO MÁGICO
        ANCHO ALTO
        MAXVAL
        DATOS_DE_PIXELES
     */

    // Borro los comentarios
    ifstream imagen_original;  imagen_original.open(path);
    if (imagen_original.is_open())
    {
        ofstream imagen_temp; imagen_temp.open("./temp.pgm");

        string line;
        while (std::getline(imagen_original, line))
        {
            if (line[0] != '#')
            {
                imagen_temp << line;
                imagen_temp << "\n";
            }
        }

        imagen_temp.close();
    }
    else
    {
        std::cout << "No se puede abrir la imagen";
    }
    imagen_original.close();

    // Abro la imagen sin comentarios
    ifstream imagen_temp; imagen_temp.open("./temp.pgm");

    vector<vector<int>> image;
    string magic = "";
    int width = -1, height = -1, max_val = -1;

    if (imagen_temp.is_open())
    {
        if (!imagen_temp.eof())
        {
            imagen_temp >> magic;
            imagen_temp >> width >> height;
            imagen_temp >> max_val;
            image = vector<vector<int>>(height, vector<int>(width));
        }
        int fila = 0, columna = 0;
        while (!imagen_temp.eof())
        {
            if (columna == width)
            {
                columna = 0;
                fila++;
            }
            imagen_temp >> image[fila][columna];
            columna++;
        }
    }
    else
    {
        std::cout << "No se puede abrir el archivo temporal";
    }
    imagen_temp.close();

    return image;
}

vector<vector<int>> read_stdio()
{
    int h = -1, w = -1;
    cin >> w >> h;
    vector<vector<int>> imagen(h, vector<int>(w));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> imagen[i][j];
        }
    }

    return imagen;
}


void save_image(vector<vector<int>> imagen, vector<int> segments, int k)
{
    int h = imagen.size();
    int w = imagen[0].size();

    //Para cada cluster un color
    map<int,rgb> clusters;

    //Inserto todos los clusters que tengo
    for (int l = 0; l < segments.size(); ++l)
    {
        rgb r;
        clusters.insert ( std::pair<int,rgb>(segments[l],r) );
    }


    vector<rgb> colors(clusters.size());
    for (int i = 0; i < colors.size(); i++)
    {
        colors[i].cero = rand()%256;
        colors[i].uno = rand()%256;
        colors[i].dos = rand()%256;
    }

    //Le asigno un color a cada cluster
    int a=0;

    for (auto it=clusters.begin(); it!=clusters.end(); ++it){
        clusters.at(it->first)=colors[a];
        a++;
    }

    vector<vector<rgb>> output;

    //A cada uno le doy el color correspondiente
    for (a = 0; a < imagen.size(); ++a) {
        vector<rgb> vacio;
        output.push_back(vacio);

        for (int i = 0; i <imagen[a].size() ; ++i) {
            int cluster = imagen[a][i];
            output[a].push_back(clusters.at(cluster));
        }
    }

    double instante_actual = clock();
    string nombre_archivo_salida = "./salida-con_k=" + to_string(k) + "-a_las=" + to_string(instante_actual) + ".ppm";

    ofstream file;
    file.open(nombre_archivo_salida);

    file << "P3\n";
    file << w << " " << h << "\n";
    file << 255 << "\n";

    //Devuelvo la imagen
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            rgb pixel = output[i][j];
            file << pixel.dos << " " << pixel.uno << " " << pixel.cero << "  ";
        }
        file << '\n';
    }

    file.close();
}

void write_stdio(vector<vector<int>> segmented_image)
{
    int h = segmented_image.size();
    int w = segmented_image[0].size();

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << segmented_image[i][j] << " ";
        }
        cout << endl;
    }

}

void segment_image_by_path(char* argv[])
{
    bool con_array = strncmp(argv[4], "array", 5) == 0;
    bool con_tree = strncmp(argv[4], "tree", 4) == 0;
    bool con_tree_pc = strncmp(argv[4], "tree_pc", 7) == 0;

    if (con_array || con_tree || con_tree_pc)
    {
        cout << "Inicia la segmentacion" << endl;

        string path = argv[2];
        int k = atoi(argv[3]);
        vector<vector<int>> imagen = read_image(path);

        if (strncmp(argv[1], "-r", 2) == 0 || strncmp(argv[1], "-R", 2) == 0)
        {
            //Numeracion de los vertices
            vector<vector<int>> vertex;
            int v = 0;
            int h = imagen.size();
            int w = imagen[0].size();

            //Armo las matrices de pixeles y numero de vertices
            for(int i = 0; i < h; ++i)
            {
                vector<int> vacio;
                vertex.push_back(vacio);
                //imagen.push_back(vacio);

                for(int j = 0; j < w; ++j){
                    int pixel;
                    //cin >> pixel;
                    //imagen[i].push_back(pixel);
                    vertex[i].push_back(v);
                    v++;
                }
            }

            //Gaussian Filter?

            //Imagen a Grafo
            graph G = image_to_graph(imagen,vertex,h,w);
            int n = h*w;
            vector<int> segments;


            if (strncmp(argv[1], "-r", 2) == 0)
            {
                if (con_array) segments = segments_by_min_distance_array(G,n,k);
                if (con_tree) segments = segments_by_min_distance_tree(G,n,k);
                if (con_tree_pc) segments = segments_by_min_distance_tree_pc(G,n,k);

                //Convierto los segmentos en formato imagen
                vector<vector<int>> segmented_image = segments_to_image(segments,h,w);
                save_image(segmented_image, segments, k);
                cout << "Imagen segmentada con k = " << k << endl;
            }
            else
            {
                while (k > 0)
                {
                    if (con_array) segments = segments_by_min_distance_array(G,n,k);
                    if (con_tree) segments = segments_by_min_distance_tree(G,n,k);
                    if (con_tree_pc) segments = segments_by_min_distance_tree_pc(G,n,k);

                    //Convierto los segmentos en formato imagen
                    vector<vector<int>> segmented_image = segments_to_image(segments,h,w);
                    save_image(segmented_image, segments, k);
                    cout << "Imagen segmentada con k = " << k << endl;

                    k = k / 2;
                }
            }
        }
        else
        {
            guide();
        }
    }
    else
    {
        guide();
    }
}

void segment_image_by_stdio(char* argv[])
{
    vector<vector<int>> imagen = read_stdio();
    //Numeracion de los vertices
    vector<vector<int>> vertex;
    int v = 0;
    int h = imagen.size();
    int w = imagen[0].size();

    //Armo las matrices de pixeles y numero de vertices
    for(int i = 0; i < h; ++i)
    {
        vector<int> vacio;
        vertex.push_back(vacio);
        //imagen.push_back(vacio);

        for(int j = 0; j < w; ++j){
            int pixel;
            //cin >> pixel;
            //imagen[i].push_back(pixel);
            vertex[i].push_back(v);
            v++;
        }
    }

    //Gaussian Filter?

    //Imagen a Grafo
    graph G = image_to_graph(imagen,vertex,h,w);
    int n = h*w;
    vector<int> segments;

    int k = rand()%3500;
    segments = segments_by_min_distance_tree_pc(G,n,k);

    vector<vector<int>> segmented_image = segments_to_image(segments,h,w);
    write_stdio(segmented_image);
}

void guide()
{
    cout << "Modos de uso:" << endl;

    cout << "1) -r path k algo: segmenta la imagen de 'path' utilizando el valor de 'k' otorgado " << flush;
    cout << "y con 'algo' = array, tree, o tree_pc" << endl;

    cout << "2) -R path k algo: segmenta la imagen de 'path' utilizando valores de 'k' decrecientes (k, k/2, k/4, ...) " << flush;
    cout << "y con 'algo' = array, tree, o tree_pc" << endl;

    cout << "3) -h: imprime esta ayuda " << endl;

    cout << "4) sin parametros: espera que le pasen por la entrada estandar un archivo con el formato especificado en el enunciado " << endl;
}