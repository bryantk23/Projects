# CMakeList.txt : CMake project for FinalProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (FinalProject "FinalProject.cpp" "ChessBoard.h"  "ChessPiece.h" "Rook.h" "Bishop.h" "Pawn.h" "Position.h" "King.h" "Queen.h" "Knight.h" "OverloadedFuncs.h")

# TODO: Add tests and install targets if needed.
