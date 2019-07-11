#include "io.h"

vector<vector<int>> read_path(string& path)
{
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


void write_path(vector<vector<int>>& imagen, vector<int>& segments, int k)
{
    int h = imagen.size();
    int w = imagen[0].size();

    map<int,rgb> clusters = get_clusters(segments);

    vector<vector<rgb>> output;

    //A cada uno le doy el color correspondiente
    for (int a = 0; a < imagen.size(); ++a) {
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
graph image_to_graph (vector<vector<int> > &image,vector<vector<int> > &vertex,int h,int w){

    graph G;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w ; ++j) {
            bool centro=true;
            //Esquina izq arriba
            if(i==0 and 0==j){
                centro=false;
                edge a,b,c;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                a.to = vertex[i][j+1];
                b.to = vertex[i+1][j];
                c.to = vertex[i+1][j+1];
                a.weight=abs(image[i][j]-image[i][j+1]);
                b.weight=abs(image[i][j]-image[i+1][j]);
                c.weight=abs(image[i][j]-image[i+1][j+1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
            }


            //Esquina der arriba
            if(i==0 and j==w-1){
                centro=false;
                edge a,b;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                a.to = vertex[i+1][j];
                b.to = vertex[i+1][j-1];
                a.weight=abs(image[i][j]-image[i+1][j]);
                b.weight=abs(image[i][j]-image[i+1][j-1]);
                G.push_back(a);
                G.push_back(b);
            }

            //Esquina der abajo
            if(i==h-1 and j==w-1){
                centro=false;
            }


            //Esquina izq abajo
            if(i==h-1 and j==0){
                centro=false;
                edge a,b,c;
                a.from = vertex[i][j];
                a.to = vertex[i][j+1];
                a.weight=abs(image[i][j]-image[i][j+1]);
                G.push_back(a);
            }

            //Fila arriba
            if(i==0 and j!=0 and j!=w-1){
                centro=false;
                edge a,b,c,d;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                d.from = vertex[i][j];
                a.to = vertex[i][j+1];
                b.to = vertex[i+1][j];
                c.to = vertex[i+1][j+1];
                d.to = vertex[i+1][j-1];
                a.weight=abs(image[i][j]-image[i][j+1]);
                b.weight=abs(image[i][j]-image[i+1][j]);
                c.weight=abs(image[i][j]-image[i+1][j+1]);
                d.weight=abs(image[i][j]-image[i+1][j-1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
                G.push_back(d);
            }

            //Fila abajo
            if(i==h-1 and j!=0 and j!=w-1){
                centro=false;
                edge a,b,c;
                a.from = vertex[i][j];
                a.to = vertex[i][j+1];
                a.weight=abs(image[i][j]-image[i][j+1]);
                G.push_back(a);
            }
            //Columna izquierda
            if(j==0 and i!=0 and i!=h-1){
                centro=false;
                edge a,b,c;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                a.to = vertex[i][j+1];
                b.to = vertex[i+1][j];
                c.to = vertex[i+1][j+1];
                a.weight=abs(image[i][j]-image[i][j+1]);
                b.weight=abs(image[i][j]-image[i+1][j]);
                c.weight=abs(image[i][j]-image[i+1][j+1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
            }

            //Columna derecha
            if(j==w-1 and i!=0 and i!=h-1){
                centro=false;
                edge a,b;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                a.to = vertex[i+1][j];
                b.to = vertex[i+1][j-1];
                a.weight=abs(image[i][j]-image[i+1][j]);
                b.weight=abs(image[i][j]-image[i+1][j-1]);
                G.push_back(a);
                G.push_back(b);
            }

            //Resto de los casos
            if(centro){
                edge a,b,c,d;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                d.from = vertex[i][j];
                a.to = vertex[i][j+1];
                b.to = vertex[i+1][j];
                c.to = vertex[i+1][j+1];
                d.to = vertex[i+1][j-1];
                a.weight=abs(image[i][j]-image[i][j+1]);
                b.weight=abs(image[i][j]-image[i+1][j]);
                c.weight=abs(image[i][j]-image[i+1][j+1]);
                d.weight=abs(image[i][j]-image[i+1][j-1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
                G.push_back(d);
            }
        }
    }

    return G;
}

vector<vector<int> > segments_to_image (vector<int> &segments,int h,int w){
    vector<vector<int> > image;
    int k=0;

    for (int i = 0; i < h ; ++i) {
        vector<int> vacio;
        image.push_back(vacio);

        for (int j = 0; j < w; ++j) {
            image[i].push_back(segments[k]);
            k++;
        }
    }

    return image;
}