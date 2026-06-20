// #include <bits/stdc++.h>
// using namespace std;

// // Minimal console chess (two-player). Features:
// // - Legal move validation for all pieces
// // - Check / Checkmate / Stalemate detection
// // - Pawn promotion to Queen (default or via =Q/R/B/N)
// // Not implemented (to keep code compact): castling, en passant, threefold/50-move.
// // Move format: e2e4, g1f3, e7e8=Q. Type 'help' for commands.

// enum class Color { None, White, Black };
// enum class PieceType { Empty, Pawn, Knight, Bishop, Rook, Queen, King };

// struct Piece {
//     PieceType t{PieceType::Empty};
//     Color c{Color::None};
// };

// struct Move {
//     int from{-1}, to{-1};
//     PieceType promo{PieceType::Empty};
// };

// struct Board {
//     array<Piece, 64> sq{};
//     Color sideToMove{Color::White};

//     static int idx(int r,int f){return r*8+f;} // r:[0..7] (rank 8..1 -> 0..7), f:[0..7] (a..h)
//     static bool inb(int r,int f){return r>=0&&r<8&&f>=0&&f<8;}

//     Piece& at(int r,int f){return sq[idx(r,f)];}
//     const Piece& at(int r,int f) const {return sq[idx(r,f)];}

//     static string name(int r,int f){ string s; s+=(char)('a'+f); s+=(char)('8'-r); return s; }

//     static pair<int,int> rfFromName(const string& s){
//         // expects like "e2". returns {-1,-1} if bad
//         if(s.size()!=2) return {-1,-1};
//         char file=tolower(s[0]), rank=s[1];
//         if(file<'a'||file>'h'||rank<'1'||rank>'8') return {-1,-1};
//         int f=file-'a';
//         int r= '8'-rank; // rank '8' -> 0, '1' -> 7
//         return {r,f};
//     }

//     static Board initial(){
//         Board b; b.sq.fill(Piece{});
//         auto set=[&](int r,int f, PieceType t, Color c){ b.at(r,f)={t,c}; };
//         // Pawns
//         for(int f=0; f<8; ++f){ set(6,f,PieceType::Pawn,Color::White); set(1,f,PieceType::Pawn,Color::Black); }
//         // Rooks
//         set(7,0,PieceType::Rook,Color::White); set(7,7,PieceType::Rook,Color::White);
//         set(0,0,PieceType::Rook,Color::Black); set(0,7,PieceType::Rook,Color::Black);
//         // Knights
//         set(7,1,PieceType::Knight,Color::White); set(7,6,PieceType::Knight,Color::White);
//         set(0,1,PieceType::Knight,Color::Black); set(0,6,PieceType::Knight,Color::Black);
//         // Bishops
//         set(7,2,PieceType::Bishop,Color::White); set(7,5,PieceType::Bishop,Color::White);
//         set(0,2,PieceType::Bishop,Color::Black); set(0,5,PieceType::Bishop,Color::Black);
//         // Queens
//         set(7,3,PieceType::Queen,Color::White); set(0,3,PieceType::Queen,Color::Black);
//         // Kings
//         set(7,4,PieceType::King,Color::White); set(0,4,PieceType::King,Color::Black);
//         b.sideToMove=Color::White;
//         return b;
//     }

//     static char pieceChar(const Piece&p){
//         char c='.';
//         switch(p.t){
//             case PieceType::Pawn: c='p'; break;
//             case PieceType::Knight: c='n'; break;
//             case PieceType::Bishop: c='b'; break;
//             case PieceType::Rook: c='r'; break;
//             case PieceType::Queen: c='q'; break;
//             case PieceType::King: c='k'; break;
//             case PieceType::Empty: default: c='.'; break;
//         }
//         if(p.c==Color::White) c=toupper(c);
//         return c;
//     }

//     void print() const {
//         cout << "\n    a b c d e f g h\n";
//         for(int r=0;r<8;++r){
//             cout << (8-r) << " | ";
//             for(int f=0; f<8; ++f){
//                 cout << pieceChar(at(r,f)) << ' ';
//             }
//             cout << "| " << (8-r) << '\n';
//         }
//         cout << "    a b c d e f g h\n";
//         cout << (sideToMove==Color::White?"White":"Black") << " to move." << "\n";
//     }
// };

// static bool isEmpty(const Piece&p){ return p.t==PieceType::Empty; }
// static bool isEnemy(const Piece&p, Color me){ return p.c!=Color::None && p.c!=me; }

// // Attack detection (for check evaluation)
// bool squareAttacked(const Board& b, int r, int f, Color by);

// // Generate pseudo-legal moves for a single piece (no self-check filtering)
// void genPieceMoves(const Board& b, int r, int f, vector<Move>& out){
//     const Piece p = b.at(r,f);
//     if(p.c==Color::None) return;
//     int dir = (p.c==Color::White? -1 : +1); // White pawns move up (toward decreasing r)

//     auto add = [&](int r1,int f1){ if(Board::inb(r1,f1)) out.push_back({Board::idx(r,f), Board::idx(r1,f1), PieceType::Empty}); };

//     switch(p.t){
//         case PieceType::Pawn: {
//             int r1=r+dir, f1=f;
//             if(Board::inb(r1,f1) && isEmpty(b.at(r1,f1))){
//                 // move one
//                 Move m{Board::idx(r,f), Board::idx(r1,f1), PieceType::Empty};
//                 // promotion?
//                 if((p.c==Color::White && r1==0) || (p.c==Color::Black && r1==7)){
//                     m.promo = PieceType::Queen; // default
//                 }
//                 out.push_back(m);
//                 // move two
//                 int startRank = (p.c==Color::White? 6:1);
//                 if(r==startRank){
//                     int r2=r+2*dir;
//                     if(Board::inb(r2,f1) && isEmpty(b.at(r2,f1)))
//                         out.push_back({Board::idx(r,f), Board::idx(r2,f1), PieceType::Empty});
//                 }
//             }
//             // captures
//             for(int df:{-1, +1}){
//                 int rf=r+dir, ff=f+df;
//                 if(Board::inb(rf,ff) && isEnemy(b.at(rf,ff), p.c)){
//                     Move m{Board::idx(r,f), Board::idx(rf,ff), PieceType::Empty};
//                     if((p.c==Color::White && rf==0) || (p.c==Color::Black && rf==7)) m.promo=PieceType::Queen;
//                     out.push_back(m);
//                 }
//             }
//             // en passant not implemented
//             break; }
//         case PieceType::Knight: {
//             const int d[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
//             for(auto &o: d){ int rr=r+o[0], ff=f+o[1]; if(!Board::inb(rr,ff)) continue; const Piece& q=b.at(rr,ff); if(q.c!=p.c) out.push_back({Board::idx(r,f),Board::idx(rr,ff),PieceType::Empty}); }
//             break; }
//         case PieceType::Bishop: {
//             const int d[4][2]={{-1,-1},{-1,1},{1,-1},{1,1}};
//             for(auto &o: d){ int rr=r+o[0], ff=f+o[1]; while(Board::inb(rr,ff)){ const Piece&q=b.at(rr,ff); if(isEmpty(q)) out.push_back({Board::idx(r,f),Board::idx(rr,ff),PieceType::Empty}); else { if(q.c!=p.c) out.push_back({Board::idx(r,f),Board::idx(rr,ff),PieceType::Empty}); break;} rr+=o[0]; ff+=o[1]; }
//             }
//             break; }
//         case PieceType::Rook: {
//             const int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//             for(auto &o: d){ int rr=r+o[0], ff=f+o[1]; while(Board::inb(rr,ff)){ const Piece&q=b.at(rr,ff); if(isEmpty(q)) out.push_back({Board::idx(r,f),Board::idx(rr,ff),PieceType::Empty}); else { if(q.c!=p.c) out.push_back({Board::idx(r,f),Board::idx(rr,ff),PieceType::Empty}); break;} rr+=o[0]; ff+=o[1]; }
//             }
//             break; }
//         case PieceType::Queen: {
//             const int d[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
//             for(auto &o: d){ int rr=r+o[0], ff=f+o[1]; while(Board::inb(rr,ff)){ const Piece&q=b.at(rr,ff); if(isEmpty(q)) out.push_back({Board::idx(r,f),Board::idx(rr,ff),PieceType::Empty}); else { if(q.c!=p.c) out.push_back({Board::idx(r,f),Board::idx(rr,ff),PieceType::Empty}); break;} rr+=o[0]; ff+=o[1]; }
//             }
//             break; }
//         case PieceType::King: {
//             const int d[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
//             for(auto &o: d){ int rr=r+o[0], ff=f+o[1]; if(!Board::inb(rr,ff)) continue; const Piece&q=b.at(rr,ff); if(q.c!=p.c) out.push_back({Board::idx(r,f),Board::idx(rr,ff),PieceType::Empty}); }
//             // castling not implemented
//             break; }
//         default: break;
//     }
// }

// bool squareAttacked(const Board& b, int r, int f, Color by){
//     // Pawns
//     int dir = (by==Color::White? -1 : +1);
//     for(int df: {-1,+1}){
//         int rr=r+dir, ff=f+df; // because to attack (r,f), pawn must be one step behind relative to its moving direction
//         if(Board::inb(rr,ff)){
//             const Piece &q=b.at(rr,ff);
//             if(q.c==by && q.t==PieceType::Pawn) return true;
//         }
//     }
//     // Knights
//     const int kn[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
//     for(auto&o:kn){ int rr=r+o[0], ff=f+o[1]; if(Board::inb(rr,ff)){ const Piece&q=b.at(rr,ff); if(q.c==by && q.t==PieceType::Knight) return true; } }
//     // Bishops/Queens (diagonals)
//     const int bd[4][2]={{-1,-1},{-1,1},{1,-1},{1,1}};
//     for(auto&o:bd){ int rr=r+o[0], ff=f+o[1]; while(Board::inb(rr,ff)){ const Piece&q=b.at(rr,ff); if(!isEmpty(q)){ if(q.c==by && (q.t==PieceType::Bishop||q.t==PieceType::Queen)) return true; else break; } rr+=o[0]; ff+=o[1]; } }
//     // Rooks/Queens (orthogonals)
//     const int rd[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//     for(auto&o:rd){ int rr=r+o[0], ff=f+o[1]; while(Board::inb(rr,ff)){ const Piece&q=b.at(rr,ff); if(!isEmpty(q)){ if(q.c==by && (q.t==PieceType::Rook||q.t==PieceType::Queen)) return true; else break; } rr+=o[0]; ff+=o[1]; } }
//     // King
//     const int kd[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
//     for(auto&o:kd){ int rr=r+o[0], ff=f+o[1]; if(Board::inb(rr,ff)){ const Piece&q=b.at(rr,ff); if(q.c==by && q.t==PieceType::King) return true; } }
//     return false;
// }

// bool inCheck(const Board& b, Color side){
//     // find king
//     for(int r=0;r<8;++r) for(int f=0;f<8;++f){ const Piece&p=b.at(r,f); if(p.c==side && p.t==PieceType::King){ return squareAttacked(b,r,f, side==Color::White?Color::Black:Color::White); }}
//     return false; // should not happen
// }

// Board makeMove(const Board& b, const Move& m){
//     Board nb=b; // copy
//     int fr=m.from, to=m.to; int frR=fr/8, frF=fr%8, toR=to/8, toF=to%8;
//     Piece moving = nb.sq[fr];
//     nb.sq[to] = moving;
//     nb.sq[fr] = Piece{};
//     // handle promotion
//     if(moving.t==PieceType::Pawn){
//         if((moving.c==Color::White && toR==0) || (moving.c==Color::Black && toR==7)){
//             nb.sq[to].t = (m.promo==PieceType::Empty? PieceType::Queen : m.promo);
//         }
//     }
//     nb.sideToMove = (b.sideToMove==Color::White? Color::Black: Color::White);
//     return nb;
// }

// vector<Move> legalMoves(const Board& b, Color side){
//     vector<Move> moves, out;
//     for(int r=0;r<8;++r) for(int f=0;f<8;++f){ const Piece&p=b.at(r,f); if(p.c!=side) continue; genPieceMoves(b,r,f,moves); }
//     // filter illegal (leave king in check)
//     for(const auto &m: moves){ Board nb=makeMove(b,m); if(!inCheck(nb, side)) out.push_back(m); }
//     return out;
// }

// string moveToString(const Move&m){ int rf=m.from/8, ff=m.from%8, rt=m.to/8, ft=m.to%8; string s=Board::name(rf,ff)+Board::name(rt,ft); if(m.promo!=PieceType::Empty){ char c='Q'; if(m.promo==PieceType::Rook) c='R'; else if(m.promo==PieceType::Bishop) c='B'; else if(m.promo==PieceType::Knight) c='N'; s.push_back('='); s.push_back(c);} return s; }

// optional<Move> parseMove(const Board& b, const string& in){
//     // Accept: e2e4, e7e8=Q, with optional spaces like "e2 e4" or uppercase files
//     string s; for(char c: in){ if(!isspace((unsigned char)c)) s.push_back(c); }
//     if(s=="help"||s=="h") return nullopt;
//     if(s.size()<4) return nullopt;
//     string a = s.substr(0,2), b2 = s.substr(2,2);
//     auto [r1,f1]=Board::rfFromName(a); auto [r2,f2]=Board::rfFromName(b2);
//     if(r1<0||r2<0) return nullopt;
//     Move m{Board::idx(r1,f1), Board::idx(r2,f2), PieceType::Empty};
//     if(s.size()>=6 && s[4]=='='){
//         char pc=toupper(s[5]);
//         if(pc=='Q') m.promo=PieceType::Queen; else if(pc=='R') m.promo=PieceType::Rook; else if(pc=='B') m.promo=PieceType::Bishop; else if(pc=='N') m.promo=PieceType::Knight;
//     }
//     // verify it's among legal moves
//     vector<Move> moves = legalMoves(b, b.sideToMove);
//     for(const auto& mv: moves){ if(mv.from==m.from && mv.to==m.to){ Move mm=mv; if(mm.promo!=PieceType::Empty) mm.promo=m.promo==PieceType::Empty?mm.promo:m.promo; return mm; } }
//     return nullopt;
// }

// bool hasKing(const Board& b, Color c){ for(const auto&p: b.sq) if(p.c==c && p.t==PieceType::King) return true; return false; }

// int main(){
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     Board b = Board::initial();
//     cout << "Simple Console Chess (C++)\n";
//     cout << "Commands: enter moves like e2e4, e7e8=Q. Type 'help' for info, 'quit' to exit.\n";
//     vector<string> history;
//     while(true){
//         b.print();
//         // Check state
//         Color us=b.sideToMove; Color them= (us==Color::White?Color::Black:Color::White);
//         bool check = inCheck(b, us);
//         vector<Move> moves = legalMoves(b, us);
//         if(moves.empty()){
//             if(check){ cout << (us==Color::White?"White":"Black") << " is in checkmate. " << (them==Color::White?"White":"Black") << " wins!\n"; }
//             else { cout << "Stalemate. Draw.\n"; }
//             break;
//         }
//         if(check) cout << "Check!\n";
//         cout << (us==Color::White?"White":"Black") << "> ";
//         string line; if(!getline(cin,line)) break; 
//         for(char &c: line) c=tolower(c);
//         if(line=="quit"||line=="exit") break;
//         if(line=="help"||line=="h"){
//             cout << "\nHow to play:\n - Input moves as from-square + to-square (e.g., e2e4, g1f3).\n - Promotions: add =Q, =R, =B, or =N (e.g., e7e8=Q).\n - This demo omits castling and en passant.\n - Check, checkmate, stalemate are detected.\n - Coordinates: files a..h, ranks 1..8.\n\n";
//             continue;
//         }
//         auto mv = parseMove(b, line);
//         if(!mv){ cout << "Illegal or unknown move. Type 'help' for syntax.\n"; continue; }
//         // play
//         Board nb = makeMove(b, *mv);
//         history.push_back(moveToString(*mv));
//         b = nb;
//     }
//     cout << "Game over. Moves played ("<<history.size()<<"):\n";
//     for(size_t i=0;i<history.size();++i){ if(i%2==0) cout << (i/2+1) << ". "; cout << history[i] << ' '; }
//     cout << "\n";
//     return 0;
// }
