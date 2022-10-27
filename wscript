def add_scratch_programs(bld):
    all_modules = [mod[len("ns3-"):] for mod in bld.env['NS3_ENABLED_MODULES'] + bld.env['NS3_ENABLED_CONTRIBUTED_MODULES']]
    obj = bld.create_ns3_program('ndn-leo', all_modules)
    obj.source = ['scratch/ndn-leo.cc',
                  'scratch/read-data.cc',
                  'scratch/model/ground-station.cc']