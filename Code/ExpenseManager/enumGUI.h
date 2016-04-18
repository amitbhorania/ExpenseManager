/*\file enumGUI.h
 *
 * \brief     Header file containing different enum definitions
 *
 * Revision History:
 *
 * Date            Author                Changes
 * 04/18/2016      Vrushali Gaikwad      Created file and adde enum definitions
 * 04/18/2016      Amit Bhorania         Updated Header Guard defines
 *
 */
#ifndef ENUMGUI_H
#define ENUMGUI_H


// Type of Graph

enum graphType_t {
        DAILY = 0,
        WEEKLY,
        MONTHLY,
        YEARLY,
        MAX_GRAPH_TYPE
};


#endif // ENUMGUI_H
