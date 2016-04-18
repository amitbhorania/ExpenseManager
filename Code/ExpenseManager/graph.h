/*\file	graph.h
*
* \brief	graph Header File containing class definition
*
* Revision History  :
*   Date            Author             Change(Describe the changes made)
*   04.18.2016      Vrushali gaikwad   Created File and added members and methods
*
*
*/
#ifndef GRAPH_H
#define GRAPH_H

// class to create graph

class graph
{
private:
        graphType_t graph_type;
        int income_data[MAX_GRAPH_LENGTH];
        int expense_data[MAX_GRAPH_LENGTH];
        string time_data[MAX_GRAPH_LENGTH];

public:
        // Display Graph on the Dashboard
                // Main Method which will call other methods to plot whole graph
                showGraph();

                // Get Graph Data from Database
                getGraphData();

                // Method to Display Graph Window
                showGraphWindow();

                // Method to Display X Axis on Graph Window
                showXAxis();

                // Method to Display Y Axis on Graph Window
                showYAxis();

                // Method to Display Bar Graph on Window
                showBarGraph();

                // Method to get the graph type given by user
                getgraphtype();

    graph();
};

#endif // GRAPH_H
