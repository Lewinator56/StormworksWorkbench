#include "obj_parser.h"

ObjParser::ObjParser()
{

}

#include <array>
#include <sstream>
#include <fstream>

using namespace std;
using uint8_t = unsigned char;





class _Triangle {
public:
    uint16_t _v1;
    uint16_t _v2;
    uint16_t _v3;

    _Triangle(uint16_t v1, uint16_t v2, uint16_t v3) {
        _v1 = v1;
        _v2 = v2;
        _v3 = v3;
    }
};

class _Normal {
public:
    float _x;
    float _y;
    float _z;
    _Normal() {

    }
    _Normal(float x, float y, float z) {
        _x = x;
        _y = y;
        _z = z;
    }
};

class _Vertex {
public:
    float _px;
    float _py;
    float _pz;
    uint8_t _r;
    uint8_t _g;
    uint8_t _b;
    uint8_t _a;
    _Normal _n;
    _Vertex(float px, float py, float pz, uint8_t r, uint8_t g, uint8_t b, uint8_t a, _Normal n) {
        _px = px;
        _py = py;
        _pz = pz;
        _r = r;
        _g = g;
        _b = b;
        _a = a;
        _n = n;
    }
    _Vertex(float px, float py, float pz, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        _px = px;
        _py = py;
        _pz = pz;
        _r = r;
        _g = g;
        _b = b;
        _a = a;
    }
    void set_Normal(_Normal n) {
        _n = n;
    }
};

class _SubMesh {
public:
    vector<_Vertex> _vertices;
    uint16_t _shader;
    float _cullingMax[3];
    float _cullingMin[3];
    vector<_Triangle> triangles;
    uint8_t _r;
    uint8_t _g;
    uint8_t _b;
    uint8_t _a;

    void add_Vertex(_Vertex v) {
        _vertices.push_back(v);
    }
    void setCullingMin(float x, float y, float z) {
        _cullingMin[0] = x < _cullingMin[0] ? x : _cullingMin[0];
        _cullingMin[1] = y < _cullingMin[1] ? y : _cullingMin[1];
        _cullingMin[2] = z < _cullingMin[2] ? z : _cullingMin[2];
    }
    void setcullingMax(float x, float y, float z) {
        _cullingMax[0] = x > _cullingMax[0] ? x : _cullingMax[0];
        _cullingMax[1] = y > _cullingMax[1] ? y : _cullingMax[1];
        _cullingMax[2] = z > _cullingMax[2] ? z : _cullingMax[2];
    }
    void setShader(uint16_t shaderID) {
        _shader = shaderID;
    }
    void add_Triangle(_Triangle t) {
        triangles.push_back(t);
    }


};

class _Color {
public:
    uint8_t _r;
    uint8_t _g;
    uint8_t _b;
    uint8_t _a;
    _Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        _r = r;
        _g = g;
        _b = b;
        _a = a;
    }
};

//string split
vector<string> split(string const& str, char const& delim) {
    stringstream ss(str);
    string s;
    vector<string> out;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
    return out;

}
template <typename T>
vector<uint8_t> getuint8_ts(T in) {
    uint8_t* uint8_tPointer = reinterpret_cast<uint8_t*>(&in);
    return vector<uint8_t>(uint8_tPointer, uint8_tPointer + sizeof(T));
}


void objToMesh(vector<string> data, string pathToOutput) {
    string error;
    try {
        uint16_t _VertexCount = 0;
        _Color c = _Color(255, 125, 0, 255);
        int _VertexPosCount = 0;
        vector<_Normal> _Normals;
        vector<int> _SubMeshVertices;
        vector<_SubMesh> _SubMeshes;
        int current_SubMesh = -1;
        _SubMeshVertices.push_back(0);
        bool need_SubMesh = true;
        cout << data.size() << endl;
        for (int i = 0; i < data.size(); i++) {
            try {
                error = data[i].substr(0, data[i].find_first_of(" "));
            }
            catch (exception e) {
                cout << "exception" << endl;
            }

            if (data[i].rfind('V', 0) == 0 && need_SubMesh == true) {
                _SubMesh s;
                s._r = c._r;
                s._g = c._g;
                s._b = c._b;
                s._a = c._a;
                current_SubMesh++;
                _SubMeshes.push_back(s);
                _SubMeshVertices.push_back(0);
                need_SubMesh = false;


            }

            // object 'o'
            if (data[i].rfind('o', 0) == 0) {
                if (data[i].find('/') != string::npos) {

                    vector<string> cv = split(split(split(data[i], ' ')[1], '/')[0], '-');
                    c._r = stoi(cv[0]);
                    c._g = stoi(cv[1]);
                    c._b = stoi(cv[2]);
                    c._a = stoi(cv[3]);
                }
                else {
                    c._r = 255;
                    c._g = 125;
                    c._b = 0;
                    c._a = 255;
                }

                if (need_SubMesh == true) {
                    _SubMesh s;
                    s._r = c._r;
                    s._g = c._g;
                    s._b = c._b;
                    s._a = c._a;
                    current_SubMesh++;
                    _SubMeshes.push_back(s);
                    _SubMeshVertices.push_back(0);
                    need_SubMesh = false;
                }
                else {
                    _SubMeshes[current_SubMesh]._r = c._r;
                    _SubMeshes[current_SubMesh]._g = c._g;
                    _SubMeshes[current_SubMesh]._b = c._b;
                    _SubMeshes[current_SubMesh]._a = c._a;
                }
            }

            // _Vertex 'v'
            else if (data[i].rfind('v', 0) == 0 && data[i].rfind("vt", 0) != 0 && data[i].rfind("vn", 0) != 0) {
                vector<string> v = split(data[i], ' ');
                float vx = stof(v[1]);
                float vy = stof(v[2]);
                float vz = stof(v[3]);
                _Vertex vtx = _Vertex(vx, vy, vz, c._r, c._g, c._b, c._a);
                _SubMeshes[current_SubMesh].add_Vertex(vtx);
                _SubMeshes[current_SubMesh].setcullingMax(vx, vy, vz);
                _SubMeshes[current_SubMesh].setCullingMin(vx, vy, vz);
                _VertexCount++;
                _SubMeshVertices[current_SubMesh + (int)1]++;
            }

            // _Vertex _Normals

            else if (data[i].rfind("vn", 0) == 0) {
                vector<string> n = split(data[i], ' ');
                float nx = stof(n[1]);
                float ny = stof(n[2]);
                float nz = stof(n[3]);
                _Normals.push_back(_Normal(nx, ny, nz));
            }

            // material usemtl
            else if (data[i].rfind("usemtl", 0) == 0) {
                uint16_t shaderID = 0;
                if (data[i].find('/') != string::npos) {
                    shaderID = stoi(split(split(data[i], ' ')[1], '/')[0]);
                }
                _SubMeshes[current_SubMesh].setShader(shaderID);
            }


            // face f
            else if (data[i].rfind('f', 0) == 0) {
                vector<string> t = split(data[i], ' ');
                int nidxv1 = stoi(split(t[1], '/')[2]) - 1;
                int nidxv2 = stoi(split(t[2], '/')[2]) - 1;
                int nidxv3 = stoi(split(t[3], '/')[2]) - 1;
                uint16_t v1 = (uint16_t)stoi(split(t[1], '/')[0]) - 1;
                uint16_t v2 = (uint16_t)stoi(split(t[2], '/')[0]) - 1;
                uint16_t v3 = (uint16_t)stoi(split(t[3], '/')[0]) - 1;
                _Triangle trg = _Triangle(v1, v2, v3);
                int toSubtract = 0;
                for (int j = 0; j < _SubMeshVertices.size() - 1; j++) {
                    toSubtract += _SubMeshVertices[j];
                }
                _SubMeshes[current_SubMesh]._vertices[v1 - (uint16_t)toSubtract].set_Normal(_Normals[nidxv1]);
                _SubMeshes[current_SubMesh]._vertices[v2 - (uint16_t)toSubtract].set_Normal(_Normals[nidxv2]);
                _SubMeshes[current_SubMesh]._vertices[v3 - (uint16_t)toSubtract].set_Normal(_Normals[nidxv3]);

                _SubMeshes[current_SubMesh].add_Triangle(trg);
                need_SubMesh = true;

            }

            // hehe, thats it for that bit, now to write it all


        }
        vector<uint8_t> mesh = {};
        // write header
        vector<uint8_t> toappend = { 0x6D, 0x65, 0x73, 0x68, 0x07, 0x00, 0x01, 0x00 };
        mesh.insert(mesh.end(), toappend.begin(), toappend.end());
        // write _Vertex cound
        toappend = getuint8_ts(_VertexCount);
        mesh.insert(mesh.end(), toappend.begin(), toappend.end());

        toappend = { 0x13, 0x00, 0x00, 0x00 };
        mesh.insert(mesh.end(), toappend.begin(), toappend.end());

        uint32_t tc = 0;
        error = "vtxDefWrie";
        for(_SubMesh sm : _SubMeshes)
        {

            for (_Vertex v : sm._vertices) {
                vector<uint8_t> vtxDef;
                toappend = getuint8_ts(v._px);
                vtxDef.insert(vtxDef.end(), toappend.begin(), toappend.end());
                toappend = getuint8_ts(v._py);
                vtxDef.insert(vtxDef.end(), toappend.begin(), toappend.end());
                toappend = getuint8_ts(v._pz);
                vtxDef.insert(vtxDef.end(), toappend.begin(), toappend.end());

                vtxDef.push_back(sm._r);
                vtxDef.push_back(sm._g);
                vtxDef.push_back(sm._b);
                vtxDef.push_back(sm._a);

                toappend = getuint8_ts(v._n._x);
                vtxDef.insert(vtxDef.end(), toappend.begin(), toappend.end());
                toappend = getuint8_ts(v._n._y);
                vtxDef.insert(vtxDef.end(), toappend.begin(), toappend.end());
                toappend = getuint8_ts(v._n._z);
                vtxDef.insert(vtxDef.end(), toappend.begin(), toappend.end());

                mesh.insert(mesh.end(), vtxDef.begin(), vtxDef.end());

            }
            tc += (uint32_t) sm.triangles.size();
        }

        toappend = getuint8_ts(tc * 3);
        mesh.insert(mesh.end(), toappend.begin(), toappend.end());

        error = "faceWrite";
        for (_SubMesh sm : _SubMeshes) {
            for(_Triangle t : sm.triangles) {
                vector<uint8_t> tDef = {};
                toappend = getuint8_ts((uint16_t)t._v1);
                tDef.insert(tDef.end(), toappend.begin(), toappend.end());
                toappend = getuint8_ts((uint16_t)t._v3);
                tDef.insert(tDef.end(), toappend.begin(), toappend.end());
                toappend = getuint8_ts((uint16_t)t._v2);
                cout << (uint16_t)t._v2 << endl;
                cout << toappend.size() << endl;

                tDef.insert(tDef.end(), toappend.begin(), toappend.end());

                mesh.insert(mesh.end(), tDef.begin(), tDef.end());

            }
        }
        toappend = getuint8_ts((uint16_t)_SubMeshes.size());
        mesh.insert(mesh.end(), toappend.begin(), toappend.end());
        uint32_t _SubMeshPosition = 0;
        error = "subWrite";

        for (_SubMesh sm : _SubMeshes) {
            toappend = getuint8_ts(_SubMeshPosition);
            mesh.insert(mesh.end(), toappend.begin(), toappend.end());
            _SubMeshPosition += (uint32_t)sm.triangles.size() * 3;
            toappend = getuint8_ts((uint32_t)sm.triangles.size() * 3);
            mesh.insert(mesh.end(), toappend.begin(), toappend.end());
            toappend = { 0x00, 0x00 };
            mesh.insert(mesh.end(), toappend.begin(), toappend.end());
            toappend = getuint8_ts(sm._shader);
            mesh.insert(mesh.end(), toappend.begin(), toappend.end());
            for (float f : sm._cullingMin) {
                toappend = getuint8_ts(f);
                mesh.insert(mesh.end(), toappend.begin(), toappend.end());
            }
            for (float f : sm._cullingMax) {
                toappend = getuint8_ts(f);
                mesh.insert(mesh.end(), toappend.begin(), toappend.end());
            }
            toappend = { 0x00, 0x00, 0x03, 0x00, 0x49, 0x44, 0x33, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F };
            mesh.insert(mesh.end(), toappend.begin(), toappend.end());
        }
        toappend = { 0x00, 0x00 };
        mesh.insert(mesh.end(), toappend.begin(), toappend.end());;


        // Stupid workaround to cater for microsoft's idiocy, and inability to follow unix standards
        ofstream fs;
        fs.open(pathToOutput, ios_base::binary | ios_base::out );
        fs.write((char*)&mesh[0], mesh.size());

        fs.close();
    }
    catch (exception e) {
        cout << "Could not convert obejct, error code: " << error << endl;
    }
}

void ObjParser::parseObj(string pathToMesh, string pathToOutput) {
    ifstream ifs;
    string line;
    vector<string> bin;
    ifs.open(pathToMesh);
    while(getline(ifs, line)) {
        bin.push_back(line);
    }
    objToMesh(bin, pathToOutput);
}


