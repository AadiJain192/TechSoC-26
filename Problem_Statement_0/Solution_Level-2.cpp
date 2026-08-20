#include <iostream>
#include <fstream>

int port_capacity, n;

void write() {
    std::ifstream file("containers.txt");
    file.close();
}

void read() {
    std::ofstream file("containers.txt");
    file.close();
}

void barchart(double weight[]) {
    std::cout << "\nContainer Weight Bar Chart : \n" << std::endl;
    int w;
    for (int i=0; i<n; i++) {
        w=weight[i]/5;
        std::cout << "Container " << i+1 << " : ";
        for (int j=0; j<w; j++) {
            std::cout << "*";
        }
        std::cout << "(" << weight[i] << ")" << std::endl;
    }
    std::cout << "\n(Each * represents 5 units)" << std::endl;
}

void diplaysorted(double sorted[]) {
    std::cout << "Containers in the sorted order: " << std::endl;
    for (int i=0; i<n; i++) {
        std::cout << sorted[i] << std::endl;
    }
}

void search(double sorted[]) {
    int f=-1;
    double weight = 0;
    std::cout << "Enter the weight to be searched: " << std::endl;
    std::cin >> weight;
    for (int i=0; i<n; i++) {
        if (weight == sorted[i]) {
            f = i;
            break;
        }
    }
    if (f == -1) {
        std::cout << "No such container found!" << std::endl;
    }
    else {
        std::cout << "Container found!" << std::endl;
        std::cout << "Container found at " << f+1 << " position." << std::endl;
    }
}

void level2(double sortedweight[], double weight[]) {
    std::cout << "\nTo do a task enter the given number." << std::endl;
    std::cout << "To display container weights in sorted order : 1" << std::endl;
    std::cout << "To display the bar chart : 2" << std::endl;
    std::cout << "To search for a container by weight : 3" << std::endl;
    std::cout << "To search for kth heaviest container : 4" << std::endl;
    int choice = 0;
    std::cin >> choice;

    switch (choice) {
        case 1: {
            diplaysorted(sortedweight);
            break;
        }
        case 2: {
            barchart(weight);
            break;
        }
        case 3: {
            search(weight);
            break;
        }
        case 4: {
            int k;
            std::cout << "Enter the number of kth heaviest container : " << std::endl;
            std::cin >> k;
            if (k <= n) {
                std::cout << "The " << k << "th heaviest container is: " <<sortedweight[n-k] << std::endl;
            }
            else {
                std::cout << "Only " << n << " containers available." << std::endl;
            }
            break;
        }
        default: {
            std::cout << "Invalid choice!" << std::endl;
            break;
        }
    }
}

int main(){

    std::cout << "Enter the maximum storage capacity of the port : " << std::endl;
    std::cin >> port_capacity;
    std::cout << "Enter the number of containers : " << std::endl;
    std::cin >> n;
    double weight[n], sortedweight[n];
    std::cout << "Enter the weight of each container : " << std::endl;
    int i, j;

    for(i=0; i<n; i++){
        std::cin >> weight[i];
        sortedweight[i] = weight[i];
    }

    double total_weight = 0;
    double average_weight = 0;
    double max;
    int pos;

    for (i=0; i<n; i++) {
        total_weight += weight[i];
        max=sortedweight[0];
        pos=0;
        for (j=0; j<n-i; j++) {
            if (max < sortedweight[j]) {
                max = sortedweight[j];
                pos = j;
            }
        }
        sortedweight[pos] = sortedweight[n-i-1];
        sortedweight[n-i-1] = max;
    }

    double max_weight = sortedweight[n-1];
    double min_weight = sortedweight[0];

    max_weight = sortedweight[n-1];
    min_weight = sortedweight[0];
    average_weight = total_weight / n;

    std::cout << "\nTotal shipment weight : " << total_weight << std::endl;
    std::cout << "Average container weight : " << average_weight << std::endl;
    std::cout << "Heaviest container : " << max_weight << std::endl;
    std::cout << "Lightest container : " << min_weight << std::endl;
    std::cout << "Classification : ";

    if (total_weight >= 200){
        std::cout << "Heavy" << std::endl;
    }
    else{
        std::cout << "Light" << std::endl;
    }

    std::cout << "Port Capacity : " << port_capacity << std::endl;

    if (total_weight <= port_capacity){
        std::cout << "Shipment can be unloaded." << std::endl;
    }
    else{
        std::cout << "Shipment exceeds port capacity." << std::endl;
    }
    char choice = 'y';
    while (choice == 'y') {
        level2(sortedweight, weight);
        std::cout << "\nEnter y to proceed else any key to exit:" << std::endl;
        std::cin >> choice;
    }


    return 0;
}