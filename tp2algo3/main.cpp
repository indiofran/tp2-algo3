#include <iostream>
#include "segmentation/segmentation.h"
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstring>
#include <random>
#include "algoritmosP2/DijkstraPQ.h"

void guide();
vector<vector<int>> read_image(string path);
void save_image(vector<vector<int>> image, vector<int> segments);

int main(int argc, char* argv[])
{
    if (argc == 3 && strncmp(argv[1], "-r", 2) == 0)
    {
        string path = argv[2];
        vector<vector<int>> imagen = read_image(path);

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
        int k = 500000;
        vector<int> segments = segments_by_min_distance_tree_pc(G,n,k);

        //Convierto los segmentos en formato imagen
        vector<vector<int>> segmented_image = segments_to_image(segments,h,w);

        save_image(segmented_image, segments);

        return 0;

        /*
        //Cout de la segmentacion
        for(int i = 0; i < h; ++i){

            for(int j = 0; i < w; ++j){
                int pixel=imagen[i][j];
                cout << pixel;
                cout<<'';
            }
            cout<<endl;
        }
        */

    }
    else
    {
        guide();
    }



    //Ejercicio 2

    //ARREGLAR

    //Cantidad de ciudades y rutas
    int n,m; cin >> n >> m;

    //Lista de Aristas
    digraph H;
    vector<int> prices;

    //Costos
    for(int i = 0; i < n; ++i){
        int c;
        cin >> c;
        prices.push_back(c);
    }

    //Grafo
    for(int i = 0; i < m; ++i){
        int weight,from,to;
        cin >> to >> from >> weight;
        //cin >> from >> to >> weight; cual va?
        for (int j = 0; j<60; j++) {  //falta el caso j=60
            directed_edge e1;
            e1.from = (from*61)+j;
            int subindiceTo = j - weight;
            if (subindiceTo<0){
                subindiceTo = 0;
            }
            int localPrice1 = prices[from];
            int edgeValue = j - weight;
            if (edgeValue<0){
                edgeValue = -edgeValue;
            } else {
                edgeValue = 0;
            }
            while(j+edgeValue <= 60) {
                e1.to = (to*61)+subindiceTo;
                e1.weight = edgeValue * localPrice1;
                H.push_back(e1);
                subindiceTo++;
                edgeValue++;
            }
            directed_edge e2; //tengo que hacer lo mismo pero del vertice to al vertice from con el valor de la nafta de to
            e2.from = (to*61)+j;
            subindiceTo = j - weight;
            if (subindiceTo<0){
                subindiceTo = 0;
            }
            int localPrice2 = prices[to];
            edgeValue = j - weight;
            if (edgeValue<0){
                edgeValue = -edgeValue;
            } else {
                edgeValue = 0;
            }
            while(j+edgeValue <= 60) {
                e2.to = (from*61)+subindiceTo;
                e2.weight = edgeValue * localPrice2;
                H.push_back(e2);
                subindiceTo++;
                edgeValue++;
            }
        }
        //j=60
        directed_edge e3;
        e3.from = (from*61)+60;
        e3.to = (to*61)+(60-weight);
        e3.weight = 0;
        H.push_back(e3);
        directed_edge e4;
        e4.from = (to*61)+60;
        e4.to = (from*61)+(60-weight);
        e4.weight = 0;
        H.push_back(e4);
    }

    int d = DijkstraPQ::dijkstraPQ2(H,(0*61),n);
/*
    for(int j = 0; j<n; j++){
        for(int i = 0; i<H.size(); i++) {
            if (H[i].from >= (j*61) && H[i].from <= (j*61)+60) {
                cout << H[i].from << "," << H[i].weight << "," << H[i].to << endl;
            }
        }
    }*/

    return 0;


}

vector<vector<int>> read_image(string path)
{
    vector<vector<int>> image;
    int width, height, formato, maximo; //Ancho y alto de la imagen a procesar

    ifstream file;
    file.open(path);
    if (file.is_open())
    {
        if (!file.eof())
        {
            // file >> formato;
            file >> width >> height;
            // file >> maximo;
            image = vector<vector<int>>(height, vector<int>(width));
        }
        int fila = 0, columna = 0;
        while (!file.eof())
        {
            if (columna == width)
            {
                columna = 0;
                fila++;
            }
            file >> image[fila][columna];
            columna++;
        }
    }
    file.close();

    return image;
}

void save_image(vector<vector<int>> imagen, vector<int> segments)
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

    ofstream file;
    file.open("./salida.ppm");

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

void guide()
{
    cout << "Hacer una guia de uso del programa" << endl;
}