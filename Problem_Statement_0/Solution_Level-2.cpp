#include <iostream>
#include <fstream>
#include <string>

int port_capacity, n;
double max_weight, min_weight, total_weight = 0, average_weight = 0;

void del(){
    std::ofstream file("Containers.txt", std::ios::trunc);
    file.close();
}

void write() {

    int l=0, f=0;
    std::string text;
    std::ifstream file("Containers.txt");
    while (std::getline(file, text)) {
        l++;
    }
    file.close();

    f=(l/9)+1;

    std::ofstream nfile("Containers.txt", std::ios::app);
    nfile << "Shipment-" << f << " : " << std::endl;
    nfile << "Maximum Capacity of port : " << port_capacity << std::endl;
    nfile << "Number of containers : " << n << std::endl;
    nfile << "Heaviest container : " << max_weight << std::endl;
    nfile << "Total shipment weight : " << total_weight << std::endl;
    nfile << "Average container weight : " << average_weight << std::endl;
    nfile << "Lightest container : " << min_weight << std::endl;
    nfile << "Classification : ";

    if (total_weight >= 200){
        nfile << "Heavy\n" << std::endl;
    }
    else{
        nfile << "Light\n" << std::endl;
    }
    nfile.close();
    std::cout << "Data wriiten in the file successfully!" << std::endl;
}

void read() {
    std::string text;
    std::ifstream file("Containers.txt");
    while (std::getline(file, text)) {
        std::cout << text << std::endl;
    }
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
    std::cout << "To save the report in a file : 3" << std::endl;
    std::cout << "To display data from the file : 4" << std::endl;
    std::cout << "To search for a container by weight : 5" << std::endl;
    std::cout << "To search for kth heaviest container : 6" << std::endl;
    std::cout << "To delete the existing data in the file : 7" << std::endl;
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
            write();
            break;
        }
        case 4: {
            read();
            break;
        }
        case 5: {
            search(weight);
            break;
        }
        case 6: {
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
        case 7: {
            del();
            break;
        }
        default: {
            std::cout << "Invalid choice!" << std::endl;
            break;
        }
    }
}

void userchoice(double sortedweight[], double weight[]) {
    char choice = 'y';
    while (choice == 'y') {
        level2(sortedweight, weight);
        std::cout << "\nEnter y to proceed else any key to exit:" << std::endl;
        std::cin >> choice;
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

    max_weight = sortedweight[n-1];
    min_weight = sortedweight[0];

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

    userchoice(sortedweight, weight);

    return 0;
}