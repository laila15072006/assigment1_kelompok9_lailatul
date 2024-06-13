from flask import Flask, request

app = Flask(__name__)

@app.route('/',methods=['POST'])
def data():
    user_data = request.get_json()
    oksigen = user_data['oksigen']
    karbondioksida = user_data['karbondioksida']
    segar = user_data['segar']
    keruh = user_data['keruh']
    nama = user_data['nama']
    return f"halo nama saya {nama}, oksigen = {oksigen}, karbondioksida = {karbondioksida},segar = {segar}, keruh = {keruh}"

if __name__ == '__main__':
    app.run(debug=True,host='0.0.0.0')