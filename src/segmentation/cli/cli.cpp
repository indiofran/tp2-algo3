#include "cli.h"

void cli(int argc, char* argv[])
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
}



void segment_image_by_path(char* argv[])
{
    bool array = strncmp(argv[4], "array", 5) == 0;
    bool tree = strncmp(argv[4], "tree", 7) == 0;
    bool tree_pc = strncmp(argv[4], "tree_pc", 7) == 0;
    bool once = strncmp(argv[1], "-r", 2) == 0;
    bool multiple = strncmp(argv[1], "-R", 2) == 0;
    bool bench = strncmp(argv[1], "-b", 2) == 0;

    if ((array || tree || tree_pc) && (once || multiple || bench))
    {
        algo_type algorithm;

        if (array) algorithm = algo_type::array;
        else if (tree) algorithm = algo_type::tree;
        else algorithm = algo_type::tree_pc;

        string path = argv[2];
        int k = atoi(argv[3]);
        vector<vector<int>> imagen = read_path(path);

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
        long long unsigned int find_count = 0, unite_count = 0, cluster_count = 0;

        if (once)
        {
            vector<int> segments = do_segmentation(G, algorithm, n, k, find_count, unite_count, cluster_count);
            vector<vector<int>> segmented_image = segments_to_image(segments,h,w);
            write_path(segmented_image, segments, k);
        }
        else if (multiple)
        {
            while (k > 0)
            {
                vector<int> segments = do_segmentation(G, algorithm, n, k,find_count, unite_count, cluster_count);
                vector<vector<int>> segmented_image = segments_to_image(segments,h,w);
                write_path(segmented_image, segments, k);
                k = k / 2;
            }
        } 
        else
        {
            cout << path << " | " << flush;
            if (array) cout << "disjoint_set sobre array" << endl << endl;
            else if (tree) cout << "disjoint_set sobre tree" << endl << endl;
            else cout << "disjoint_set sobre tree con path compression" << endl << endl;

            while (k > 0)
            {
                vector<int> segments = do_segmentation_and_bench(G, algorithm, n, k, find_count, unite_count, cluster_count);
                vector<vector<int>> segmented_image = segments_to_image(segments,h,w);
                write_path(segmented_image, segments, k);
                k = k / 2;
            }
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
    int k = rand()%3500;
    long long unsigned int find_count = 0, unite_count = 0, cluster_count = 0;

    vector<int> segments = do_segmentation(G, algo_type::tree_pc, n, k, find_count, unite_count, cluster_count);
    vector<vector<int>> segmented_image = segments_to_image(segments,h,w);
    write_stdio(segmented_image);
}

vector<int> do_segmentation(graph& G, algo_type algorithm, int n, int k, long long unsigned int& find_count, long long unsigned int& unite_count, long long unsigned int& cluster_count)
{
    vector<int> segments;

    switch (algorithm)
    {
        case algo_type::array:
            segments = segments_by_min_distance_array(G, n, k, find_count, unite_count);
            break;
        case algo_type::tree:
            segments = segments_by_min_distance_tree(G, n, k, find_count, unite_count);
            break;
        case algo_type::tree_pc:
            segments = segments_by_min_distance_tree_pc(G, n, k, find_count, unite_count);
            break;
        default:
            break;
    }

    return segments;
}

vector<int> do_segmentation_and_bench(graph& G, algo_type algorithm, int n, int k, long long unsigned int& find_count, long long unsigned int& unite_count, long long unsigned int& cluster_count)
{
    int SAMPLES_COUNT = 1;

    vector<int> segmentation;
    chrono::high_resolution_clock::time_point begin, end;
    chrono::nanoseconds delta;
    vector<chrono::nanoseconds> deltas;

    cout << endl;
    cout << "SEGMENTACION INICIADA CON: n = " << n << ", k = " << k << endl;

    for (int i = 0; i < SAMPLES_COUNT; i++)
    {
        begin = chrono::high_resolution_clock::now();
        segmentation = do_segmentation(G, algorithm, n, k, find_count, unite_count, cluster_count);
        end = chrono::high_resolution_clock::now();
        delta = end - begin;
        deltas.push_back(delta);
    }

    long long unsigned int avg = average(deltas);

    cout << "TERMINADA EN: " << avg << " ns. en promedio (" << SAMPLES_COUNT << " muestras)" << endl;
    cout << "\t - # find: " << find_count << endl;
    cout << "\t - # unite: " << unite_count << endl;
    cout << "\t - # cluster: " << get_clusters(segmentation).size() << endl;
    cout << endl;

    return segmentation;
}

long long unsigned int average(vector<chrono::nanoseconds>& deltas)
{
    long long unsigned int avg = 0;
    for (auto delta : deltas)
    {
        avg += delta.count();
    }
    avg = avg / deltas.size();

    return avg;
}

void guide()
{
    cout << "Modos de uso:" << endl;

    cout << "1) -r path k algo: segmenta la imagen de 'path' utilizando el valor de 'k' otorgado " << flush;
    cout << "y con 'algo' = array, tree, o tree_pc" << endl;

    cout << "2) -R path k algo: segmenta la imagen de 'path' utilizando valores de 'k' decrecientes (k, k/2, k/4, ...) " << flush;
    cout << "y con 'algo' = array, tree, o tree_pc" << endl;

    cout << "3) -b path k algo: realiza un benchmark realizando lo mismo que 2) pero adicionalmente " << flush;
    cout << "imprimiendo por pantalla los tiempos." << endl;

    cout << "4) -h: imprime esta ayuda " << endl;

    cout << "5) sin parametros: espera que le pasen por la entrada estandar un archivo con el formato especificado en el enunciado " << endl;
}