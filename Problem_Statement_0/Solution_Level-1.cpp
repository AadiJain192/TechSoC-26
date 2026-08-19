#include <iostream>
#include <string>

int main(){
    int port_capacity, n;
    std::cout << "Enter the maximum storage capacity of the port : " << std::endl;
    std::cin >> port_capacity;
    std::cout << "Enter the number of containers : " << std::endl;
    std::cin >> n;
    double weight[n];
    std::cout << "Enter the weight of each container : " << std::endl;
    int i;

    for(i=0; i<n; i++){
        std::cin >> weight[i];
    }
    double total_weight = 0;
    double max_weight = weight[0];
    double min_weight = weight[0];
    double average_weight = 0;
    
    for(i=0; i<n; i++){
        total_weight += weight[i];
        if (max_weight < weight[i])
        {
            max_weight = weight[i];
        }
        else if (min_weight > weight[i])
        {
            min_weight = weight[i];
        }
        
    }
    average_weight = total_weight / n;

    std::cout << "Total shipment weight : " << total_weight << std::endl;
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
        std::cout << "Shipment can be unloaded. " << std::endl;
    }
    else{
        std::cout << "Shipment exceeds port capacity." << std::endl;
    }

    return 0;
}