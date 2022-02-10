#pragma once

#include "../../LinkedList.h"
#include "../utils.h"

void testDeleteFrontEmptyListThrowsException();
void testDeleteFrontNonEmptyList();
void testDeleteBackEmptyListThrowsException();
void testDeleteBackNonEmptyList();
void testDeleteMidInvalidPositionThrowsException();
void testDeleteMidValidPosition();
void runDeleteTests();